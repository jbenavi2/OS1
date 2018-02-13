#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "threads.h"
#include "q.h"

TCB_t *RunQ;  //global header RunQ

void thread1(){
    int x = 0;

    while (1){
        printf("x = %d\n", x);
        x++;
        yield();
        sleep(1);
    }
}

void thread2(){
    int y = 5;
    while(1){
        printf("y = %d\n", y);
        y++;
        yield();
        sleep(1);
    }
}

int main() {
    TCB_t *RunQ;
    //RunQ = malloc(sizeof(TCB_t));
    InitQueue(&RunQ);
    start_thread(thread1);
    start_thread(thread2);
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


    

    printf("hello, world");
    return 0;
}