#include <math.h>
#include "common.h"


bool accept (double delta, double temper)
{
  if (delta >= 0) return true;
  return random () <= exp ((delta) / temper) * RAND_MAX;
}

double run_annealing(int *start, int *len, int dim, double dec, int *iter_tmp)
{
  int *tmp = (int *) malloc (dim *sizeof (int));
  int *next = (int *) malloc (dim *sizeof (int));
  int *best = (int *) malloc (dim *sizeof (int));
  double best_fit = 0.0f;
  int i = 0;
  double cur_fit, pre_fit;
  memcpy (tmp, start, dim * sizeof (int));
  memcpy (next, start, dim * sizeof (int));
  int iter = 0;
  int var;
  double temp = 0.5f;


  while (temp > 0.001)
  {
	iter ++;
	for (i = 0;i < dim; i++)
	{
	  var = random () % 80;
	  if (next[i] + var < len[i])
	  {
	    tmp[i] = next[i] + var;
	  }
	  else
	  {
	    tmp[i] = next[i] - var;
	  }
	}
	cur_fit = fitness_degree(tmp, dim);
	pre_fit = fitness_degree(next, dim);
	if (accept(cur_fit - pre_fit, temp))
	{
	  memcpy(next, tmp, dim*sizeof(int));
	  //print_process (cur_fit, next, dim, iter);
	}
	if (cur_fit > best_fit)
	{
	  best_fit = cur_fit;
	  memcpy(best, tmp, dim*sizeof(int));
	}

	temp *= dec;
  }
  //print_process (best_fit, best, dim, iter);
  
  *iter_tmp = iter;
  free (tmp);
  free (next);
  free (best);
  return best_fit;
}
