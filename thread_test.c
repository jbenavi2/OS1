/*
 * Javier Benavides
 * CSE 330 Project 1
 * Due 2/16/2018
 * */




#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "threads.h"
#include "q.h"
#include "sem.h"

TCB_t *RunQ;  //global header RunQ
int global_a = 0;

Semaphore *empty, *full, *mutex;

void Producer_1(){
    int local_x = 0;
    while(1){
        P(empty);
        P(mutex);
        local_x++;
        printf("Producer 1:  local count = %d, global count = %d\n", local_x, global_a);
        global_a++;
        sleep(2);
        V(mutex);
        V(full);

    }
}
void Producer_2(){
    int local_x = 0;
    while(1){
        P(empty);
        P(mutex);
        local_x = local_x + 2;
        printf("Producer 2:  local count = %d, global count = %d\n", local_x, global_a);
        global_a++;
        sleep(2);
        V(mutex);
        V(full);

    }
}

void Consumer_1(){
    int local_x = 0;
    while (1){
        P(full);
        P(mutex);
        local_x--;
        printf("Consumer 1:  local count = %d, glocal count = %d\n", local_x, global_a);
        global_a++;
        sleep(2);
        V(mutex);
        V(empty);
    }
}

void Consumer_2(){
    int local_x = 0;
    while (1){
        P(full);
        P(mutex);
        local_x = local_x - 2;
        printf("Consumer 2:  local count = %d, glocal count = %d\n", local_x, global_a);
        global_a++;
        sleep(2);
        P(mutex);
        V(empty);
    }
}


int main() {
    TCB_t *RunQ;
    full = malloc(sizeof(Semaphore));
    empty = malloc(sizeof(Semaphore));
    mutex = malloc(sizeof(Semaphore));

    full->tcb_wait = malloc(sizeof(TCB_t));
    empty->tcb_wait = malloc(sizeof(TCB_t));
    mutex->tcb_wait = malloc(sizeof(TCB_t));

    InitQueue(&RunQ);
    InitQueue(&(full->tcb_wait));
    InitQueue(&(empty->tcb_wait));
    InitQueue(&(mutex->tcb_wait));

    InitSem(full, 0);
    InitSem(empty, 1);
    InitSem(mutex, 1);

    start_thread(Producer_1);
    start_thread(Producer_2);
    start_thread(Consumer_1);
    start_thread(Consumer_2);
    run();

/// These are the previous tests done for part 1
//    queueElement **head;
//    head = malloc(sizeof(queueElement));
//    int i;
//
//    InitQueue(head);
//
//    queueElement *item;
//
//    for (i = 0; i < 10; i++){
//        item = NewItem();
//        item->payload = i;
//        AddQueue(head, item);
//    }
//
//    PrintQ(*head);
//
//    for (i = 0; i < 5; i++){
//        item = DelQueue(head);
//        printf("Item deleted %d\n", item->payload);
//    }
//
//    RotateQ(head);
//
//    item = DelQueue(head);
//
//    printf("item Deleted %d\n", item->payload);
//
//    PrintQ(*head);
//
//    RotateQ(head);
//
//    PrintQ(*head);
//
//    item = NewItem();
//    item->payload= 15;
//    AddQueue(head, item);
//
//    PrintQ(*head);
//
//    RotateQ(head);
//
//    PrintQ(*head);


    

    //printf("hello, world");
    return 0;
}