#ifndef _UNITS_H_
#define _UNITS_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <windows.h>

#include "solvers.h"
#include "utils.h"
#include "user.h"
#include "delay_out.h"

int OneTest(double *tests);
int unit_test();
bool check_func(COEF *coefficents, ROOTS* roots, int counter);

#endif

