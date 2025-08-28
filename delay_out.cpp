#include "delay_out.h"

void split_output(const char* input_string) {
    assert(input_string);
    int cnt = strlen(input_string);
    for (int i = 0; i < cnt; i++) {
        printf("%c", input_string[i]);
        Sleep(50);
    }
}

