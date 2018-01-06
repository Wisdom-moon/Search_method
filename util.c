#include <stdio.h>

void print_process (double fitness, int *next, int dim, int iter)
{
  printf("[Info] %d iteration, %lf fitness, value = (", iter, fitness);
  int i = 0;
  for (i = 0; i < dim - 1; i++)
    printf("%d, ", next[i]);
  printf ("%d)\n", next[i]);
}
