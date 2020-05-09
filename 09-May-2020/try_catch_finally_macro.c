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

#define TD_THROW() crash_normal_c()
#define TD_CATCH
#define TD_FINALLY
#define TD_TRY(try_block, catch_block, finally_block) if (setjmp(buf) == 1) catch_block \
                                                      else try_block \
                                                      finally_block

void (*signal(int signum, void (*sighandler)(int)))(int);
void recover_on_signal(int sig_num);
jmp_buf buf;

// derefencing a NULL pointer causes exception
// the program will crahsh from here, but we can 
// signal and setjmp to recover from segfault
void crash_normal_c() {
    int *p = NULL;
    *p=0xdead; 
}

void test_try_catch() {
    TD_TRY ({
        TD_THROW();
        
    }, TD_CATCH {
        printf("We catch the error\n");
        
    }, TD_FINALLY {
        printf("Cleaning up \n");
        
    })
    printf("End of the program\n");
}

int main(int argc, char** argv) {
    signal(SIGSEGV, recover_on_signal);
    
    test_try_catch();
}

void recover_on_signal(int sig_num) {
    switch (sig_num) {
        case SIGSEGV:
            longjmp(buf, 1);
            break;
    }
}