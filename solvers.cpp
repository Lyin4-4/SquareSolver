#include "user.h"
#include "utils.h"
#include "solvers.h"

int linear_equation(COEF *coefficents, ROOTS* roots) {

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
            roots->x1 = 0;
        else
            roots->x1 = -coefficents->c / coefficents->b;
        return ONE_SOL;
    }
}

int square_equation(COEF* coefficents, ROOTS* roots) {
    assert(coefficents);
    assert(roots);

    if (compare_with_zero(coefficents->c)){

        roots->x2 = 0;
        linear_equation(coefficents, roots);

        return TWO_SOL;
    }

    double disc = (coefficents->b * coefficents->b) - (4 * coefficents->a * coefficents->c); /*������������ ����������� ���������*/


    if (compare_doubles(disc, 0) == LESS) {
        return ZERO_SOL;
    }
    else if (compare_with_zero(disc)) {
        roots->x1 = roots->x2 = -coefficents->b / (2 * coefficents->a);
        return TWO_SOL;
    }

    double sq_disc = sqrt(disc);

    roots->x1 = (-coefficents->b + sq_disc) / (2 * coefficents->a);
    roots->x2 = (-coefficents->b - sq_disc) / (2 * coefficents->a);

    return TWO_SOL;

}


int equation(COEF* coefficents, ROOTS* roots) {
    assert(coefficents);
    assert(roots);
    if (compare_with_zero(coefficents->a)){
        return linear_equation(coefficents, roots);
    }
    else {
        return square_equation(coefficents, roots);
    }
}

void start_solver() {
    do {
        split_output("Put in programm coefficents: \n");

        COEF coefficents;
        coefficents.a = 0;
        coefficents.b = 0;
        coefficents.c = 0;
        int count_roots = 0; /*#���������� ������ ����������� ���������*/
        ROOTS roots; /*#����� ����������� ��������� */
        roots.x1 = 0;
        roots.x2 = 0;
        input(&coefficents);

        count_roots = equation(&coefficents, &roots);
        output(count_roots, &roots, &coefficents);
        split_output("Do you need to solve one more equation?\nPlease text [y/n]\n");
        } while (check_answer('y', 'n'));
}
