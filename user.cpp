#include "user.h"

void start_loading() {
    int steps = 700;
    for (int i = 0; i <= 700; i++) {
        double percentage = ((double)i / steps) * 100;
        if (i == 373) {
            _getch();
            split_output("\n\033[35mAlright, Alright, Alright. I continue)\033[0m\n");
        }

        printf("Loading: %.2f%%\r", percentage);
        fflush(stdout);
        Sleep(30);
    }
    split_output("\033[32mLoading complete!\033[0m\n");
}


void input(COEF *coefficents) {
    while (scanf("%lg %lg %lg", &(coefficents->a), &(coefficents->b), &(coefficents->c)) != 3) {
        split_output("Fuuuuuuuck!\nNigga, text only numeric type\nPut in programm coefficents: \n");
        clear_buf();
    }
    clear_buf();
}

void start_input() {
    bool check_user = check_answer('u', 'q');
    if (check_user) {
        split_output("OK, I'm starting unit testing.\n") ;
        if (!(unit_test())) {
            printf("Unit-tests ERROR\n");
        } else{
            split_output("\033[32mUnit-tests is OK\033[0m\n");
            split_output("Do you want to run a quadratic equation solver? Write \033[33m[y/n]\033[0m:\n");
            bool check_solver = check_answer('y', 'n');
            if (check_solver) {
                start_solver();
            }
        }
    } else{
        split_output("Hi, that programm is square solver\n");
        start_solver();
    }
}

void equation_output(COEF* coefficents) {
    assert(coefficents);   // assert
    int sign_a = compare_doubles(coefficents->a, 0);
    int sign_b = compare_doubles(coefficents->b, 0);
    int sign_c = compare_doubles(coefficents->c, 0);
    int cond_sign = 1;
    printf("\n"); // x² + 4·x + 5 = 0

    if (sign_a == ABOVE){
        if (compare_doubles(coefficents->a, 1) == EQUAL)
            split_output("x^2 ");
        else {
        printf("%lg", coefficents->a);
        split_output("x^2 ");
        }
    } else if (sign_a == LESS) {
        if (compare_doubles(coefficents->a, -1) == EQUAL)
            split_output("-x^2 ");
        else {
        split_output("- ");
        printf("%lg", coefficents->a);
        split_output("x^2 ");
        }
    } else {
        cond_sign = 0;
    }

    if (cond_sign){
        if (sign_b == ABOVE) {
            if (compare_doubles(coefficents->b, 1) == EQUAL)
                split_output("+ x ");
            else {
                split_output("+ ");
                printf("%lg", coefficents->b);
                split_output("x ");
            }
        } else if (sign_b == LESS) {
            cond_sign = 1;
            if (compare_doubles(coefficents->b, -1) == EQUAL)
                split_output("- x ");
            else {
            split_output("- ");
            printf("%lg", coefficents->b);
            split_output("x ");
            }
        }
    } else {
        if (sign_b == ABOVE) {
            cond_sign = 1;
            if (compare_doubles(coefficents->b, 1) == EQUAL)
                split_output("x ");
            else {
                printf("%lg", coefficents->b);
                split_output("x ");
            }
        } else if (sign_b == LESS) {
            cond_sign = 1;
            if (compare_doubles(coefficents->b, -1) == EQUAL)
                split_output("-x ");
            else {
            printf("%lg", coefficents->b);
            printf("x ");
            }
        }
    }

    if (cond_sign){
        if (sign_c == ABOVE) {
                split_output("+ ");
                printf("%lg", coefficents->c);
                split_output(" ");
        } else if (sign_c == LESS) {
            split_output("- ");
            printf("%lg", coefficents->c);
            split_output(" ");
        }
    } else {
        printf("%lg", coefficents->c);
        split_output(" ");
    }
    split_output("= 0\n");
}

void output(int num_of_solut, ROOTS* roots, COEF* coefficents) {
    assert(roots);
    switch(num_of_solut) {
        case INF_SOL:
            equation_output(coefficents);
            split_output("Infinity solutions\n\n");
            break;
        case ZERO_SOL:
            equation_output(coefficents);
            split_output("No solutions\n\n");
            break;
        case ONE_SOL:
            equation_output(coefficents);
            split_output("One solution: ");
            printf("%lg\n\n", roots->x1);
            break;
        case TWO_SOL:
            equation_output(coefficents);
            split_output("Two solutions: x1 = ");
            printf("%lg", roots->x1);
            split_output(", x2 = ");
            printf("%lg", roots->x2);
            split_output("\n\n");
            break;
        default: split_output("Something went wrong\n\n");
            break;
    }
}

bool check_answer(char var1, char var2){
    while (true) {
        char ch = getchar();
        if (ch != var1 && ch != var2 && ch != '\n' && ch != EOF) {
            printf("Please text only \033[33m[%c/%c]\033[0m\n", var1, var2);
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
               split_output("I counted your first character, but there are others besides it. Please be more careful next time\n");
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
