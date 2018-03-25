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
    TCB_t *tcb_queue;
}Semaphore;

void InitSem(Semaphore *sem, int value){
    sem->tcb_queue = (TCB_t*)malloc(sizeof(TCB_t));
    sem->value = value;


}

void P(Semaphore *sem){

    sem->value--;

    if(sem->value < 0){
        TCB_t *T = DelQueue(RunQ);
        AddQueue(sem->tcb_queue, T);
        swapcontext(&(T->context), &(RunQ->context));

    }
}

void V(Semaphore *sem){

    sem->value++;

    if(sem->value <= 0){
        TCB_t *T = DelQueue(sem->tcb_queue);
        AddQueue(RunQ, T);
        yield();


    }
}







#endif //OS1_SEM_H
