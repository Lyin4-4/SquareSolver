#ifndef _SOLVERS_H_
#define _SOLVERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "delay_out.h"

typedef struct {
    double a = 0, b = 0, c = 0;
} COEF;

typedef struct {
    double x1 = 0, x2 = 0;
} ROOTS;

enum variants_solutions {
    INF_SOL = - 1,
    ZERO_SOL = 0,
    ONE_SOL = 1,
    TWO_SOL = 2,
};


int square_equation(COEF* coefficents, ROOTS* roots);
int equation(COEF* coefficents, ROOTS* roots);
int linear_equation(COEF *coefficents, ROOTS* roots);

void start_solver();

#endif
