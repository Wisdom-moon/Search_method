#include "common.h"

#define MAX_TIME 65536
#define INDEX_DIM(x,len) \
	(x[0] + x[1] * len[0])

static double *ref_data = NULL;
static int *length;

void init_data (char * file_name, int *len, int dim)
{
  FILE * fd = fopen(file_name, "r");
  char *line = NULL;
  size_t size = 1;
  int i = 0;
  int j = 0;
  for (i = 0; i < dim; i++)
	size *= len[i];
  ref_data = (double *) malloc ( size * sizeof (double));
  length = (int *) malloc (dim * sizeof (int));
  memcpy (length, len, dim *sizeof (int));
  for (i = 0; i < size; i++)
    //ref_data[i] = MAX_TIME;
    ref_data[i] = 0.0;

  double time;
  int places, blocks;
/*
  while(getline(&line, &size, fd) != -1)
  {
    if (sscanf(line, "%d %d %lf", &places, &blocks, &time) == 3)
    {
	places --;
	blocks --;
	ref_data[places * len[0] + blocks] = time;
    }
  }
*/
  for (i = 0; i < len[1]; i++)
    for (j = 0; j < len[0]; j++)
	fscanf (fd, "%lf", &ref_data[i * len[0] + j]);
}

double  fitness_degree (int *cur, int dim)
{
  int i = 0;
  if (ref_data == NULL)
  {
      printf("The data is not init.\n");
      return -1.0f;
  }
  for (i = 0; i < dim; i++)
  {
    if (cur[i] < 0 || cur[i] >= length[i])
	return 0.0f;
  }

  //return ref_data[0] / ref_data[cur[0] + cur[1] * length[0]];
  return ref_data[cur[0] + cur[1] * length[0]];
}
