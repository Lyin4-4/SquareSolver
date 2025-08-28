#include "units.h"

int OneTest(double *tests) {
    assert(tests);
    ROOTS roots_1;
    int num_of_roots_ref = (int)tests[3];
    COEF coef = {};
    coef.a = tests[0];
    coef.b = tests[1];
    coef.c = tests[2];
    int numeric_of_roots = equation(&coef, &roots_1);
    if (compare_with_zero(coef.a) && compare_with_zero(coef.b)) {
        if (compare_with_zero(coef.c)) {
            return numeric_of_roots == INF_SOL;
        }
        return numeric_of_roots == ZERO_SOL;
    }
    if (numeric_of_roots != num_of_roots_ref) {
        return 0;
    }
    else {
        if (num_of_roots_ref == TWO_SOL) {
            if (!(check_func(&coef, &roots_1, numeric_of_roots) && check_func(&coef, &roots_1, numeric_of_roots)))
                return 0;
            return 1;
        } else if (num_of_roots_ref == ONE_SOL) {
            if (!(check_func(&coef, &roots_1, numeric_of_roots)))
                return 0;
            return 1;
        }
        return 1;
    }
}

int unit_test(){
    double tests[8][4] =
    {
        {1, 2, 1, 2},
        {0, 5, 0, 1},
        {0, 0, 0, -1},
        {1, 6, -7, 2},
        {0, 5, 0, 1},
        {0.5, 0, 0, 2},
        {5, 0, 0, 2},
        {1, 1, 1, 0}
    };

    int i = 0;

    while (i < 8) {
        //printf("uhcvuc%lg %lg %lg %lg\n", tests[i][0], tests[i][1], tests[i][2], tests[i][3]);
        if (!(OneTest(tests[i]))) {
            split_output("\033[31mFUCK(\nI need to change my programm\033[0m\n");
            return 0;
        }
        ++i;
    }
    return 1;
}

bool check_func(COEF *coefficents, ROOTS* roots, int counter) {
    if (counter == TWO_SOL) {
        if (compare_with_zero(coefficents->a * roots->x1 * roots->x1 + coefficents->b * roots->x1 + coefficents->c) &&
        compare_with_zero(coefficents->a * roots->x1 * roots->x1 + coefficents->b * roots->x1 + coefficents->c)) {
            return true;
        }
        return false;
    } else {
        if (compare_with_zero(coefficents->a * roots->x1 * roots->x1 + coefficents->b * roots->x1 + coefficents->c)) {
            return true;
        }
        return false;
    }
}
