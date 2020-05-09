/*!gcc '{0}' -I. -I../include/ -o out; ./out --cester-verbose */

/*
# the else execute only if the condition
become false
num = 11;
while (num > 0 ):
    print("At number ", num)
    num = num - 1
else:
    print("Cannot iterate number")
*/
#include <stdio.h>

#define HD_ELSE 
#define HD_WHILE(cond, body, else_body) while (cond) body else_body

int main(int argc, char** argv) {
    int num = -1;
    HD_WHILE(num --> 0, {
        printf("At number %d\n", num);
        
    }, HD_ELSE {
        printf("Done with the loop");
    })
}