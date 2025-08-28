#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <windows.h>
#include <math.h>

enum compare_variants {
    ABOVE = 1,
    LESS = -1,
    EQUAL = 0,
};

const double EPS = 1e-10;

char compare_with_zero(double a);
int compare_doubles(double x, double y);
void clear_buf();
#endif
