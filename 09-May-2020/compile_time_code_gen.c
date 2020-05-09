/*!gcc '{0}' -I. -I../include/ -o out; ./out --cester-verbose */

#include "compile_time_generator.h"

/*
This example generates our 
code at compile time
*/

TD_RUN(test_name, {
    printf("We are running our code here \n");
    printf("Booyah ");
})

TD_RUN(test_two, {
    printf("Function two\n");
})

TD_RUN(test_three, {
    printf("Function two\n");
})
