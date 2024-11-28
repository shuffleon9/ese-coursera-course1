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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <platform.h>
#include "stats.h"


/* Add other Implementation File Code Here */
void print_statistics(unsigned char* arr, unsigned int length) {
    printf("Median: %d\n", find_median(arr, length));
    printf("Mean: %.d\n", find_mean(arr, length));
    printf("Maximum: %d\n", find_maximum(arr, length));
    printf("Minimum: %d\n", find_minimum(arr, length));
}

void print_array(unsigned char* arr, unsigned int length) {
#ifdef VERBOSE 
    PRINTF("Array: ");
    for (int i = 0; i < length; i++) {
        PRINTF("%d ", arr[i]);
    }
    PRINTF("\n");
#endif
}

unsigned char find_median(unsigned char* arr, unsigned int length) {
    unsigned char* copyArr = (unsigned char*) malloc(length * sizeof(unsigned char));
    for (int i = 0; i < length; i++)
        copyArr[i] = arr[i];

    sort_array(copyArr, length);

    unsigned char res;
    if (length % 2 == 0) {
        res = (copyArr[length / 2 - 1] + copyArr[length / 2]) / 2;
    }
    else {
        res = copyArr[length / 2];
    }

    free(copyArr);
    return res;
}

unsigned char find_mean(unsigned char* arr, unsigned int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return (sum / length);
}

unsigned char find_maximum(unsigned char* arr, unsigned int length) {
    unsigned char max = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

unsigned char find_minimum(unsigned char* arr, unsigned int length) {
    unsigned char min = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void sort_array(unsigned char* arr, unsigned int length) {
    unsigned char tmp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] < arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}