
#ifndef CODEGENER
#define CODEGENER

#include <stdio.h>
#include <stdlib.h>

typedef void (*td_function)();

#define TD_RUN(x,y) static void x();

#include __BASE_FILE__
#undef TD_RUN

#define TD_RUN(x,y) x,

static void* our_functions[] = {
#include __BASE_FILE__
NULL
};
#undef TD_RUN

#define TD_RUN(x,y) static void x() { y }

int main(int argc, char** argv) {
    int i;
    for (i=0;our_functions[i] != NULL;++i) {
        ((td_function)our_functions[i])();
    }
}

#endif