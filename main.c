#include <time.h>
#include "common.h"


int main (int argc, char **argv)
{
  char * file_name = NULL;

  int i = 1;
  int j = 0;
  int k;
  int dim = 0;
  int *len;
  int *start;
  while ( i < argc)
  {
	if (argv[i][0] == '-')
	{
		switch (argv[i][1])
		{
			case 'f':
			  file_name = argv[++i];
			  break;
			case 'd':
			  dim = atoi(argv[++i]);
			  len = (int *) malloc (dim * sizeof (int));
			  for (j = 0; j < dim; j++)
			  {
				len[j] = atoi (argv[++i]);
			  }
			  break;
			case 'h':
			  printf("Usage: -f file_name -d dim len1 len2 ...\n");
			  break;
			default:
			  break;
		}
	}
	i ++;
  }
  init_data (file_name, len, dim);

  struct timespec tp;
  clock_gettime (CLOCK_REALTIME, &tp);
  srandom (tp.tv_nsec);

  start = (int *) malloc (dim * sizeof (int));

  //run_hill_climbing (start, dim);
  double dec = 0.999;
  double fit;
  int iter;
  for ( i = 0 ; i < 100; i++)
  {
    fit = 0.0f;
    for (j = 0; j < 20; j++)
    {
      for ( k = 0; k < dim; k++)
      {
        start[k] = random() % len[k];
      }
      fit += run_annealing(start, len, dim, dec, &iter);
    }
    fit = fit / 20;
    printf("%d %lf\n", iter, fit);
    dec += 0.00001;
    if (dec > 0.999999999)
      break;
  }

  free (len);
  free (start);
}
