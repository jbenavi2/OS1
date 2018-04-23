

#ifndef PROJECT_3_THREADS_H
#define PROJECT_3_THREADS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "q.h"
#include <ucontext.h>

void start_thread(void (*function)(void))
{

    void *stackP = malloc(8192);
    TCB_t *tcb = NewItem();
    init_TCB(tcb, function, stackP, 8192);
    AddQueue(runQ, tcb);
}

void run()
{
    ucontext_t parent;
    getcontext(&parent);
    swapcontext(&parent, &runQ->head->context);
}

void yield()
{
    ucontext_t current_context;
    getcontext(&current_context);
    runQ->head->context = current_context;
    RotateQ(runQ);
    ucontext_t new_context = runQ->head->context;
    swapcontext(&current_context, &new_context);
}

#endif //PROJECT_3_THREADS_H