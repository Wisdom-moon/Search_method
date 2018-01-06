#ifndef _COMMON_H_
#define _COMMON_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void run_hill_climbing(int *start, int dim);
void init_data (char * file_name, int *len, int dim);
double  fitness_degree (int *cur, int dim);
void print_process (double fitness, int *next, int dim, int iter);
double run_annealing(int *start, int *len, int dim, double dec, int *iter);
#endif 
