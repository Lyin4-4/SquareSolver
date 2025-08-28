#include "utils.h"

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

void clear_buf() {
    char ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
