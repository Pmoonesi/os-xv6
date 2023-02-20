#include "types.h"
#include "stat.h"
#include "user.h"

#define PAGESIZE 4096

void* get_stack(){
    void *fptr;
    void *stack;

    while((fptr = malloc(2 * PAGESIZE)) == 0);
    
    int mod = (uint)fptr % PAGESIZE;

    if(mod == 0)
        stack = fptr;
    else
        stack = fptr + (PAGESIZE - mod);

    return stack;
}

int main(void){
    int value = 0;
    int count = 0;
    int units1[3] = {0, 2, 3};
    int units2[4] = {0, 2, 0, 3};
    printf(1, "first\n");

    int tid;
    void* stack;
    // creating task1
    stack = get_stack();
    tid = createtask((void*)stack, units1, count, value);
    if (tid == 0)
        exit();

    // creating task2
    stack = get_stack();
    tid = createtask((void*)stack, units2, count, value);
    if (tid == 0)
        exit();

    int i;
    for(i = 0; i < 4; i++){
        printf(1, "%d\n", i);
        stack = get_stack();
        tid = unit_operation((void*)stack, i);
        if (tid == 0)
            exit();
    }

    printf(1, "last\n");

    while((i=threadwait())>0);

    printf(1,"test done %d\n", tid);

    exit();
}