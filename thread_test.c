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

TCB_t *RunQ;  //global header RunQ
int a = 0;

void thread1(){
    int x = 0;

    while (1){
        printf("Thread 1\n");
        printf("local x = %d\n", x);
        printf("global a = %d\n\n", a);
        x++;
        a++;
        yield();
        sleep(2);
    }
}

void thread2(){
    int y = 5;
    while(1){
        printf("Thread 2\n");
        printf("local y = %d\n", y);
        printf("global a = %d\n\n", a);
        y++;
        a++;
        yield();
        sleep(2);
    }
}

void thread3(){
    int z = 10;
    while(1){
        printf("Thread 3\n");
        printf("local z = %d\n", z);
        printf("global a = %d\n\n", a);
        z++;
        a++;
        yield();
        sleep(2);
    }
}

int main() {
    TCB_t *RunQ;
    InitQueue(&RunQ);
    start_thread(thread1);
    start_thread(thread2);
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