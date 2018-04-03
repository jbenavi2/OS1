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

int store[10];
int produce, consume = 0;

Semaphore *empty, *full, *ProducerMutex, *ConsumerMutex;

void Producer_1(){

    while(1){
        P(empty);
        P(ProducerMutex);

        store[produce] = 1;
        produce = (produce + 1) % 10;
        printf("Producer #1: ");
        int i;
        for(i = 0; i < 10; i++){
            printf("%d\t", store[i]);
        }
        printf("\n");
        sleep(2);

        V(ProducerMutex);
        V(full);
    }
}

void Producer_2(){

    while(1){
        P(empty);
        P(ProducerMutex);

        store[produce] = 1;
        produce = (produce + 1) % 10;
        printf("Producer #2: ");
        int i;
        for(i = 0; i < 10; i++){
            printf("%d\t", store[i]);
        }
        printf("\n");
        sleep(2);

        V(ProducerMutex);
        V(full);
    }
}

void Consumer_1(){

    while(1){
        P(full);
        P(ConsumerMutex);

        store[consume] = 0;
        consume = (consume + 1) % 10;
        printf("Consumer #1: ");
        int i;
        for(i = 0; i < 10; i++){
            printf("%d\t", store[i]);
        }
        printf("\n");
        sleep(2);

        V(ConsumerMutex);
        V(empty);
    }
}

void Consumer_2(){

    while(1){
        P(full);
        P(ConsumerMutex);

        store[consume] = 0;
        consume = (consume + 1) % 10;
        printf("Consumer #2: ");
        int i;
        for(i = 0; i < 10; i++){
            printf("%d\t", store[i]);
        }
        printf("\n");
        sleep(2);

        V(ConsumerMutex);
        V(empty);
    }
}

int main() {

    RunQ = InitQueue();
    InitSem(full, 0);
    InitSem(empty, 10);
    InitSem(ProducerMutex, 1);
    InitSem(ConsumerMutex, 1);

    int i;
    for(i = 0; i < 10; i++){
        store[i] = 0;
    }

    start_thread(Producer_1);
    start_thread(Producer_2);
    start_thread(Consumer_1);
    start_thread(Consumer_2);

    run();


//    TCB_t *RunQ;
//    full = malloc(sizeof(Semaphore));
//    empty = malloc(sizeof(Semaphore));
//    //mutex = malloc(sizeof(Semaphore));
//
//    full->tcb_waitQ = malloc(sizeof(TCB_t));
//    empty->tcb_waitQ = malloc(sizeof(TCB_t));
//   // mutex->tcb_waitQ = malloc(sizeof(TCB_t));
//
//    InitQueue(&RunQ);
//    InitQueue(&(full->tcb_waitQ));
//    InitQueue(&(empty->tcb_waitQ));
//   // InitQueue(&(mutex->tcb_waitQ));
//
//    InitSem(full, 0);
//    InitSem(empty, 1);
//   // InitSem(mutex, 1);
//
//    start_thread(Producer_1);
//  //  start_thread(Producer_2);
//   // start_thread(Consumer_1);
//   // start_thread(Consumer_2);
//    run();

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