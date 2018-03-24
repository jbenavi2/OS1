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

}









#endif //OS1_SEM_H
