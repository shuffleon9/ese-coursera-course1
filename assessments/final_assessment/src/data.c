#include "data.h"


/***********************************************************
 Function Definitions
***********************************************************/

uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base) {
    if (base < 2 || base > 16) {
        return 0;
    }

    uint8_t length = 0;
    uint8_t isNegative = 0;

    if (data < 0 && base == 10) {
        isNegative = 1;
        data = -data;
    }

    uint8_t* start_ptr = ptr;
    do {
        int remainder = data % base;
        data /= base;

        if (remainder < 10) {
            *ptr = '0' + remainder;
        }
        else {
            *ptr = 'A' + (remainder - 10);
        }
        ptr++;
        length++;
    } while (data != 0);

    if (isNegative) {
        *ptr = '-';
        ptr++;
        length++;
    }

    *ptr = '\0';
    length++;

    // Reverse the string
    uint8_t* end_ptr = ptr - 1;
    ptr = start_ptr;
    while (ptr < end_ptr) {
        uint8_t temp = *ptr;
        *ptr = *end_ptr;
        *end_ptr = temp;

        ptr++;
        end_ptr--;
    }

    return length;
}


int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base) {
    if (base < 2 || base > 16) {
        return -1;
    }

    int32_t res = 0;
    uint8_t isNegative = 0;
    int i = 0;
    while (i < digits) {
        if (*ptr == '-') {
            isNegative = 1;
        }
        else if (*ptr >= '0' && *ptr <= '9') {
            res = res * base + (*ptr - '0');
        }
        else if (*ptr >= 'A' && *ptr <= 'F') {
            res = res * base + (*ptr - 'A' + 10);
        }

        ptr++;
        i++;
    }

    if (isNegative) res = -res;

    return res;
}
