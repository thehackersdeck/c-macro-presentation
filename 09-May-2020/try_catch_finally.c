/*!gcc '{0}' -I. -I../include/ -o out; ./out --cester-verbose */

/*
A typical try, catch and finally in java 
try {
    
} catch {
    
} finally {
    
}
*/

#include <stdio.h>
#include <stdlib.h>

#include <signal.h> // to set signal and what error to recover from 
#include <setjmp.h> // marking and jumping to a point in the program 

void (*signal(int signum, void (*sighandler)(int)))(int);
void recover_on_signal(int sig_num);

jmp_buf buf;

// derefencing a NULL pointer causes exception
// the program will crahsh from here, but we can 
// signal and setjmp to recover from segfault
void crash_normal_c() {
    int *p = NULL;
    *p=0xdead; 
    printf("No segfaulkt\n");
}

int main(int argc, char** argv) {
    signal(SIGSEGV, recover_on_signal);
    switch (setjmp(buf)) {
        case 1:
            
            break;
        default:
            crash_normal_c();
            break;
    }
    printf("The end of the program, we recovered \nWooooo\n");
}

void recover_on_signal(int sig_num) {
    switch (sig_num) {
        case SIGSEGV:
            printf("Recovering from segfault\n");
            longjmp(buf, 1);
            break;
    }
}