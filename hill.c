#include "common.h"


void run_hill_climbing(int *start, int dim)
{
  int *tmp = (int *) malloc (dim *sizeof (int));
  int *next = (int *) malloc (dim *sizeof (int));
  int i = 0;
  double cur_fit, max_fit;
  max_fit = 0.0f;
  memcpy (tmp, start, dim * sizeof (int));
  memcpy (next, start, dim * sizeof (int));
  int is_stop = 0;
  int iter = 0;

  while (is_stop == 0)
  {
	is_stop = 1;
	iter ++;
	for (i = 0;i < dim; i++)
	{
	  tmp[i]++;
	  cur_fit = fitness_degree(tmp, dim);
	  if (cur_fit > max_fit)
	  {
		memcpy(next, tmp, dim*sizeof(int));
		max_fit = cur_fit;
		is_stop = 0;
		print_process (max_fit, next, dim, iter);
	  }
	  tmp[i] -= 2;
	  cur_fit = fitness_degree(tmp, dim);
	  if (cur_fit > max_fit)
	  {
		memcpy(next, tmp, dim*sizeof(int));
		max_fit = cur_fit;
		is_stop = 0;
		print_process (max_fit, next, dim, iter);
	  }
	  tmp[i]++;
	}
	memcpy (tmp, next, dim*sizeof(int));
  }
  
  free (tmp);
  free (next);
}
