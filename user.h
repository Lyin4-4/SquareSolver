#ifndef _USER_H_
#define _USER_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "units.h"
#include "solvers.h"
#include "utils.h"
#include "delay_out.h"

void equation_output(COEF* coefficents);
void output(int num_of_solut, ROOTS* roots, COEF* coefficents);

void input(COEF *coefficents);
void start_loading();
void start_input();
void split_output(char input_string[]);

bool check_answer(char var1, char var2);


#endif
