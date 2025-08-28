#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <Windows.h>
//#include <wingdi.h>
#include "user.h"
#include "delay_out.h"




int main() {
    //SetTextColor(stdout, 0x000000FF);
    start_loading();
    split_output("Salaam alaikum, fraerok, ");
    split_output("what the fuck do you want:\nTo do unit testing or open a quadratic equation solver??\n");
    split_output("Enter \033[33m[u/q]\033[0m, only \033[33mu\033[0m or \033[33mq\033[0m only them. No need to introduce other nonsense:\n");
    start_input();

    return 0;
}


