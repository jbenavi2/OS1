//
// Created by echob on 2/12/2018.
//

#ifndef OS1_THREADS_H
#define OS1_THREADS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q.h"
#include <ucontext.h>

//global header runQ
Queue *RunQ;

//Step 2
void start_thread(void (*function)(void)){
    void *stack = malloc(8192);
//    TCB_t *tcb = (TCB_t*)malloc(sizeof(TCB_t));
    TCB_t *tcb = NewItem();
    init_TCB(tcb, function, stack, 8192);
    AddQueue(RunQ, tcb);
}

//step 3:  Write routines called "yield" and "run" which cranks up the works
void run(){
    ucontext_t parent;
    getcontext(&parent);
//    swapcontext(&parent, &(RunQ->context));
    swapcontext(&parent, &RunQ->head->context);
}

void yield(){
    ucontext_t *from;
    ucontext_t *to;
    from = &RunQ->head->context;
    RotateQ(RunQ);
    to = &RunQ->head->context;
    swapcontext(from, to);

}


#endif //OS1_THREADS_H
