/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief This file is to be used for the c1m3 assessment.
 *
 * This file provides various memory allocations. The learner will need
 * to analyze the code's memory footprint for this assessment.
 *
 * @author Alex Fosdick
 * @date April 2, 2017
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include "misc.h"

static int g1;			// g1: data/bss 	(rw, program)	-> uninitialized global/static variable
const int g2 = 45;		// g2: code/rodata 	(r, program)	-> const variable
char g3 = 12;			// g3: data/data	(rw, program)	-> initialized global/static variable
char g4 = 0;			// g4: data/bss		(rw, program)	-> zero-initialized global/static variable
extern char g5[N];		

int main()				// main: code/text	(r, program)	-> executable code
{
  register int l1;		// l1: register		(rw, function)	-> register keyword
  int * l2;				// l2: data/stack	(rw, function)	-> local variable
						// *l2: data/heap	(rw, indefinite)-> dynamic-allocated memory
  volatile int l3 = 12;	// l3: data/stack	(rw, function)	-> local variable
  
  l2 = (int *) malloc( N * g2 * sizeof(char) );

  if ( ! l2 )
  {
    return -1;
  }

  for( l1 = 0; l1 < g2; l3++)
  {
    g1 = func(l2);
  }

  return 0;
}

