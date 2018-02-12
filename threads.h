//
// Created by echob on 2/12/2018.
//

#ifndef OS1_THREADS_H
#define OS1_THREADS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q.h"

//global header runQ
TCB_t *runQ;

//Step 2
void start_thread(void (*function)(void)){
    void *stack = malloc(8192);
    TCB_t *tcb = (TCB_t*)malloc(sizeof(TCB_t));
    init_TCB(tcb, function, stack, 8192);
    AddQueue(&runQ, tcb);
}






#endif //OS1_THREADS_H
