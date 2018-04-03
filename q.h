//
// Created by echob on 2/10/2018.
//

#ifndef OS1_Q_H
#define OS1_Q_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tcb.h"


//node of a doubly linked list
typedef struct queueElement{
    int payload;
    struct queueElement *next;      //pointer to next node
    struct queueElement *previous;  //pointer to previous node
}queueElement;

typedef struct Queue{
    struct TCB_t *head;
}Queue;


//returns a pointer to a new q-element
TCB_t *NewItem(){
    TCB_t *item = (TCB_t*)malloc(sizeof(TCB_t));
    item->next = NULL;
    item->prev = NULL;
    return item;
}

//creates empty queue pointed to by the variable head
//void InitQueue(TCB_t **head){
//    *head = NULL;
//}
Queue *InitQueue(){
    return (Queue*)malloc(sizeof(Queue));
}

//adds a queue item, pointed to by "item", to the queue pointed to by head
void AddQueue(Queue *q, TCB_t *item) {

    //check if the queue is empty.  if so, make this the head and have it point to itself
    if (q->head == NULL) {

        q->head = item;
        q->head->prev = q->head;
        q->head->next = q->head;
    }
        //place new item at the end
    else {
        //last element next pointer goes to new item
        q->head->prev->next = item;

        //new item previous pointer goes to prior last element
        item->prev = q->head->prev;

        //new item next pointer goes to head
        item->next = q->head;

        //head previous pointer goes to new item
        q->head->prev = item;
    }
}

//deletes an item from head and returns a pointer to the deleted item
TCB_t *DelQueue(Queue *q){


    //check if queue is already empty
    if (q->head == NULL){
        return NULL;
    }

    //if there is only one element in the queue
    //which happens only if the element points to itself
    if (q->head->next == q->head && q->head->prev == q->head){
        TCB_t *tmp = q->head;
        q->head = NULL;
        return tmp;

    }
    //more than one element
    else{
        //previous pointer of element after head points to the last element
        q->head->next->prev = q->head->prev;

        //next pointer of last element points to element after head
        q->head->prev->next = q->head->next;

        //make element after head the new head
        q->head = q->head->next;
    }

    //maybe add a return here too
}

//Moves the header pointer to the next element in the queue
void RotateQ(Queue *q){
    q->head = q->head->next;
}

void PrintQ(TCB_t *head){
    TCB_t *tmp = head;

    while (tmp->next != head){
        printf("%d ", tmp->context);
        tmp = tmp->next;
    }
    printf("%d \n", tmp->context);
}




#endif //OS1_Q_H
