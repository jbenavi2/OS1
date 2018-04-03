//
// Created by echob on 3/24/2018.
//

#ifndef OS1_SEM_H
#define OS1_SEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q.h"
#include "tcb.h"
#include "threads.h"

typedef struct Semaphore{
    int value;
    Queue *tcb_waitQ;
}Semaphore;

void InitSem(Semaphore *sem, int value){
    sem = (Semaphore*)malloc(sizeof(Semaphore));
    sem->value = value;
    sem->tcb_waitQ = InitQueue();

}

void P(Semaphore *sem){

    sem->value--;

    if(sem->value < 0){
        TCB_t *T = DelQueue(RunQ);
        AddQueue(sem->tcb_waitQ, T);
        swapcontext(&(T->context), &RunQ->head->context);

    }
}

void V(Semaphore *sem){

    sem->value++;

    if(sem->value <= 0){
        TCB_t *T = DelQueue(sem->tcb_waitQ);
        AddQueue(RunQ, T);



    }

    yield();
}







#endif //OS1_SEM_H
