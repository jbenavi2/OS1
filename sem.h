

#ifndef PROJECT_2_SEM_H
#define PROJECT_2_SEM_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "q.h"
#include "tcb.h"
#include "threads.h"

typedef struct Semaphore
{
    int value;
    Queue *tcb_queue;
} Semaphore;

Semaphore *InitSem(int value);
void P(Semaphore *sem);
void V(Semaphore *sem);

Semaphore * InitSem(int value)
{
    Semaphore *sem = ALLOC(Semaphore);
    sem->value = value;
    sem->tcb_queue = InitQueue();
    return sem;
}

void P(Semaphore *sem)
{
    sem->value--;
    if(sem->value < 0)
    {
        TCB_t *tcb = DelQueue(runQ);
        AddQueue(sem->tcb_queue, tcb);
        swapcontext(&tcb->context, &runQ->head->context);
    }
}

void V(Semaphore *sem)
{
    sem->value++;
    if (sem->value <= 0)
    {
        TCB_t *tcb = DelQueue(sem->tcb_queue);
        AddQueue(runQ, tcb);
    }
    yield();
}



#endif //PROJECT_2_SEM_H