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
 * @file misc.h 
 * @brief This file is to be used for the c1m2 assesment
 *
 * @author Alex Fosdick
 * @date April 2, 2017
 *
 */
#include "misc.h"

#define SOME_VALUE (6)						// SOME_VALUE: none -> preprocessed (no memory)

int g5[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};// g5: data/data	(rw, program)	-> initialized global/static variable

int func(int * f1)							// func: code/text	(r, program)	-> executable code
{											// f1: data/stack	(rw, function)	-> function argument
  static int f2;							// f2: data/bss		(rw, program)	-> zero-initialized global/static variable
  unsigned int f3 = 0;						// f3: data/stack	(rw, function)	-> local variable
  volatile char * f4 = "Hello World!\n"; 	// "Hello World": code/rodata -> (r, program) -> string literal

  f2++;
  *(&g5[0] + f2) = f3;

  for (f3 = 0; f3 < SOME_VALUE; f3++)
  {
    g5[f3] = f4[f3];
    f2++;
  }

  return f2;
}

