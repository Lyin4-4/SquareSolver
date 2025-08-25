#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <Windows.h>
//#include <wingdi.h>
#include <stdlib.h>

// read about struct and add ..
// раздельная компиляция

enum variants_solutions {
    INF_SOL = -1,
    ZERO_SOL = 0,
    ONE_SOL = 1,
    TWO_SOL = 2,
};



enum compare_variants {
    ABOVE = 1,
    LESS = -1,
    EQUAL = 0,
};

const double EPS = 1e-10;

struct COEF {
    double a = NAN, b = NAN, c = NAN;
};

bool check_func(double check_mas[3], double x1);
char compare_with_zero(double a);
int compare_doubles(double x, double y);
int linear_equation(double a, double b,
                        double *roots);
int square_equation(double* coefficents, double* roots);
int equation(double coefficents[3], double* roots);
void output(int num_of_solut, double* roots);
void clear_buf();
void input(double* coefficents);
bool check_answer(char var1, char var2);
int OneTest(double tests[4]);
int unit_test();
void start_solver();
void start_input();

int main() {
    //SetTextColor(stdout, 0x000000FF);
    printf("Salaam alaikum, fraerok, ");
    printf("what the fuck do you want:\nTo do unit testing or open a quadratic equation solver??\n");
    printf("Enter [u/q], only u or q only them. No need to introduce other nonsense:\n");
    start_input();

    return 0;
}


bool check_func(COEF *coefficents, double x1) {

    if ((coefficents->a * x1 * x1 + coefficents->b * x1 + coefficents->c) == 0) {
        return true;
    }
    return false;
}


// ---------------------------------
//! @brief Сравнения числа типа double с нулем
//!
//!@param[in] coefficents[0]  coefficents[0] - число типа double, которое мы сравниваем
//!
//!@return Равно ли число нулю
// ---------------------------------

char compare_with_zero(double a) {
    assert(isfinite(a));
    return fabs(a) < EPS;
}


int compare_doubles(double x, double y) {
    assert(isfinite(x));
    assert(isfinite(y));

    if (fabs(x - y) < EPS) {
        return EQUAL;

    } else if ((x - y) > EPS) {
        return ABOVE;
    } else {
        return LESS;
    }
}

int linear_equation(COEF *coefficents,
                        double *roots) {

    assert(roots);
    assert(coefficents);
    if (compare_with_zero(coefficents->b)) {
        if (compare_with_zero(coefficents->c)) {
            return INF_SOL;
        }
        return ZERO_SOL;
    }
    else{
        if (compare_with_zero(coefficents->c))
            roots[0] = 0;
        else
            roots[0] = -coefficents->c / coefficents->b;
        return ONE_SOL;
    }
}


int square_equation(COEF* coefficents, double* roots) {
    assert(coefficents);
    assert(roots);

    if (compare_with_zero(coefficents->c)){  //

        roots[1] = 0;
        linear_equation(coefficents, &roots[0]);

        return TWO_SOL;
    }

    double disc = coefficents->b * coefficents->b - 4 * coefficents->a * coefficents->c; /*Дискриминант квадратного уравнения*/


    if (disc < -EPS) {
        return ZERO_SOL;
    }
    else if (compare_with_zero(disc)) {
        roots[0] = roots[1] = -coefficents->b / (2 * coefficents->a);
        return TWO_SOL;
    }

    double sq_disc = sqrt(disc);

    roots[0] = (-coefficents->b + sq_disc) / (2 * coefficents->a);
    roots[1] = (-coefficents->b - sq_disc) / (2 * coefficents->a);

    return TWO_SOL;

}


int equation(COEF* coefficents, double* roots) {
    assert(coefficents);
    assert(roots);
    if (compare_with_zero(coefficents->a)){
        return linear_equation(coefficents, roots);
    }
    else {
        return square_equation(coefficents, roots);
    }
}

void equation_output(COEF* coefficents) {
    int sign_a = compare_doubles(coefficents->a, 0);
    int sign_b = compare_doubles(coefficents->b, 0);
    int sign_c = compare_doubles(coefficents->c, 0);
    int cond_sign = 1;
    printf("\n");
    if (sign_a == ABOVE){
        if (compare_doubles(coefficents->a, 1) == EQUAL)
            printf("x^2 ");
        else {
        printf("%lgx^2 ", coefficents->a);
        }
    } else if (sign_a == LESS) {
        if (compare_doubles(coefficents->a, -1) == EQUAL)
            printf("-x^2 ");
        else {
        printf("-%lgx^2 ", coefficents->a);
        }
    } else {
        cond_sign = 0;
    }


    if (cond_sign){
        if (sign_b == ABOVE) {
            if (compare_doubles(coefficents->b, 1) == EQUAL)
                printf("+ x ");
            else {
                printf("+ %lgx ", coefficents->b);
            }
        } else if (sign_b == LESS) {
            cond_sign = 1;
            if (compare_doubles(coefficents->b, -1) == EQUAL)
                printf("- x ");
            else {
            printf("- %lgx ", coefficents->b);
            }
        }
    } else {
        if (sign_b == ABOVE) {
            cond_sign = 1;
            if (compare_doubles(coefficents->b, 1) == EQUAL)
                printf("x ");
            else {
                printf("%lgx ", coefficents->b);
            }
        } else if (sign_b == LESS) {
            cond_sign = 1;
            if (compare_doubles(coefficents->b, -1) == EQUAL)
                printf("-x ");
            else {
            printf("%lgx ", coefficents->b);
            }
        }
    }

    if (cond_sign){
        if (sign_c == ABOVE) {
                printf("+ %lg ", coefficents->c);
        } else if (sign_c == LESS) {
            printf("- %lg ", fabs(coefficents->c));
        }
    } else {
        printf("%lg ", coefficents->c);
    }
    printf("= 0\n");
}

void output(int num_of_solut, double* roots, COEF* coefficents) {
    assert(roots);
    switch(num_of_solut) {
        case INF_SOL:
            equation_output(coefficents);
            printf("Infinity solutions\n\n");
            break;
        case ZERO_SOL:
            equation_output(coefficents);
            printf("No solutions\n\n");
            break;
        case ONE_SOL:
            equation_output(coefficents);
            printf("One solution: %lg\n\n", roots[0]);
            break;
        case TWO_SOL:
            equation_output(coefficents);
            printf("Two solutions: x1 = %lg, x2 = %lg\n\n", roots[0], roots[1]);
            break;
        default: printf("Something went wrong\n\n");
            break;
    }
}

void clear_buf() {
    char ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF);
}


void input(COEF *coefficents) {
    while (scanf("%lg %lg %lg", &(coefficents->a), &(coefficents->b), &(coefficents->c)) != 3) {
        printf("Fuuuuuuuck!\nNigga, text only numeric type\n");
        printf("Put in programm coefficents: \n");
        clear_buf();
    }
    clear_buf();
}

bool check_answer(char var1, char var2){
    while (true) {
        char ch = getchar();
        if (ch != var1 && ch != var2 && ch != '\n' && ch != EOF) {
            printf("Please text only [%c/%c]\n", var1, var2);
            clear_buf();
        }
        else {
            char next_element = getchar();
            if (next_element == '\n' || next_element == EOF) {

                if (ch == var1) {
                    return true;
                }
                else{
                    return false;
                }
            }
            else {
               printf("I counted your first character, ");
               printf("but there are others besides it. ");
               printf("Please be more careful next time\n");
               clear_buf();
               if (ch == var1) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
}

int OneTest(double tests[4]) {   // rename
    assert(tests);
    double roots[2] = {};
    int num_of_roots_ref = (int)tests[3];
    COEF coef;
    coef.a = tests[0];
    coef.b = tests[1];
    coef.c = tests[2];
    int numeric_of_roots = equation(&coef, roots);
    if (numeric_of_roots != num_of_roots_ref) {
        return 0;
    }
    else {
        if (num_of_roots_ref == TWO_SOL) {
            if (!(check_func(&coef, roots[0]) && check_func(&coef, roots[1])))
                return 0;
            return 1;
        } else if (num_of_roots_ref == ONE_SOL) {
            if (!(check_func(&coef, roots[0])))
                return 0;
            return 1;
        }
    }
}

int unit_test(){
    double tests[5][4] =
    {
        {1, 2, 1, 2},
        {0, 5, 0, 1},
        {1, 5, 6, 2},
        {1, 6, -7, 2},
        {2, 4, 2, 2}
    };

    int i = 0;

    while (i < 5) {
        //printf("uhcvuc%lg %lg %lg %lg\n", tests[i][0], tests[i][1], tests[i][2], tests[i][3]);
        if (!(OneTest(tests[i]))) {
            printf("FUCK(\nI need to change my programm\n");
            return 0;
        }
        ++i;
    }
    return 1;
}

void start_solver() {
    do {
        printf("Put in programm coefficents: \n");

        COEF coefficents;
        coefficents.a = 0;
        coefficents.b = 0;
        coefficents.c = 0;
        int count_roots = 0; /*#Количество корней квадратного уравнения*/
        double roots[2] = {}; /*#Корни квадратного уравнения */
        input(&coefficents);

        count_roots = equation(&coefficents, roots);
        output(count_roots, roots, &coefficents);
        printf("Do you need to solve one more equation?\nPlease text [y/n]\n");
        } while (check_answer('y', 'n'));
}

void start_input() {
    bool check_user = check_answer('u', 'q');
    if (check_user) {
        printf("OK, I'm starting unit testing.\n") ;
        if (!(unit_test())) {
            printf("Unit-tests ERROR\n");
        } else{
            printf("Unit-tests is OK\n");
            printf("Do you want to run a quadratic equation solver? Write [y/n]:\n");
            bool check_solver = check_answer('y', 'n');
            if (check_solver) {
                start_solver();
            }
        }
    } else{
        printf("Hi, that programm is square solver\n");
        start_solver();
    }
}

