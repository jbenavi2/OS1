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

void thread3(){
    int z = 10;
    while(1){
        printf("Thread 3\n");
        printf("local z = %d\n", z);
        printf("global a = %d\n\n", global_a);
        z++;
        global_a++;
        yield();
        sleep(2);
    }
}

int main() {
    TCB_t *RunQ;
    InitQueue(&RunQ);
    start_thread(thread3);
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