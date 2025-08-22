#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>

// read calloc and dynamic memory

enum variants_solutions {
    INF_SOL = -1,
    ZERO_SOL = 0,
    ONE_SOL = 1,
    TWO_SOL = 2,
};


const double EPS = 1e-10;

// add github
char compare_doubles(double a) {
    return fabs(a) < EPS;
}

int Linear_equation(double a, double b,
                        double *x1){
    if (compare_doubles(a)) {
        if (compare_doubles(b)) {
            return INF_SOL;
        }
        return ZERO_SOL;
    }
    else{
        *x1 = -b / a;
        return ONE_SOL;
    }
}

int Square_equation(double a, double b, double c,
                        double *x1, double *x2) {

    assert(x1);
    assert(x2);

    if (compare_doubles(a)) {
        return Linear_equation(b, c, x1);
    }
    else if (compare_doubles(c) && !compare_doubles(b)) {
            *x2 = 0;
            return Linear_equation(a, b, x1);
    }
    double disc = b * b - 4 * a * c; /*Дискриминант квадратного уравнения*/


    if (disc < -EPS) {
        return ZERO_SOL;
    }
    else if (compare_doubles(disc)) {
        *x1 = *x2 = -b / (2 * a);
        return TWO_SOL;
    }

    double sq_disc = sqrt(disc);
    *x1 = (-b + sq_disc) / (2 * a);
    *x2 = (-b - sq_disc) / (2 * a);

    return TWO_SOL;

}

int equation(double &a, double &b, double &c,
                        double *x1, double *x2) {
    if (compare_doubles(a)){
        return Linear_equation(b, c, x1);
    }
    else if (!compare_doubles(a) && !compare_doubles(b) && compare_doubles(c)){

    }
}

void output(int num_of_solut, double *x1, double *x2) {
    switch(num_of_solut) {
        case INF_SOL: printf("Infinity solutions");
            break;
        case ZERO_SOL: printf("No solutions");
            break;
        case ONE_SOL: printf("One solution: %lg", x1);
            break;
        case TWO_SOL: printf("Two solutions: x1 = %lg, x2 = %lg\n", *x1, *x2);        // read about %lg]
            break;
        default: printf("Something went wrong");
            break;
    }
}

void clear_buf(char &ch) {
    ch = getchar();
    while (ch != '\n' && ch != EOF)
        ch = getchar();
}

void input(double &a, double &b, double &c) {
    while (scanf("%lg %lg %lg", &a, &b, &c) != 3) {
        printf("ti dolbaeb, a ni che tot fakt chto nado chisla vvodit`\n");
        char ch = 0;
        clear_buf(ch);
    }
}

int main() {
    double a = NAN, b = NAN, c = NAN; /*#Коэффиценты уравнения a, b, c*/
    int count_roots = 0; /*#Количество корней квадратного уравнения*/
    double x1 = NAN, x2 = NAN; /*#Корни квадратного уравнения */

    printf("Hi, that programm in square solver\n");
    printf("Put in programm coefficents: \n");


    input(a, b, c);

    count_roots = Square_equation(a, b, c, &x1, &x2);
    output(count_roots, &x1, &x2);

    return 0;
}
