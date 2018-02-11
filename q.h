//
// Created by echob on 2/10/2018.
//

#ifndef OS1_Q_H
#define OS1_Q_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//node of a doubly linked list
typedef struct queueElement{
    int payload;
    struct queueElement *next;      //pointer to next node
    struct queueElement *previous;  //pointer to previous node
}queueElement;

//queueElement *head = NULL;
//queueElement *tail = NULL;

//returns a pointer to a new q-element
queueElement *NewItem(){
    queueElement *item = (queueElement*)malloc(sizeof(queueElement));
    item->next = NULL;
    item->previous = NULL;
    return item;
}

//creates empty queue pointed to by the variable head
void InitQueue(queueElement **head){
    *head = NULL;
}

//adds a queue item, pointed to by "item", to the queue pointed to by head
void AddQueue(queueElement **head, queueElement *item) {

    //check if the queue is empty.  if so, make this the head and have it point to itself
    if (*head == NULL) {
        item->next = item;
        item->previous = item;

        *head = item;
    }
        //place new item at the end
    else {
        //last element next pointer goes to new item
        (*head)->previous->next = item;

        //new item previous pointer goes to prior last element
        item->previous = (*head)->previous;

        //new item next pointer goes to head
        item->next = *head;

        //head previous pointer goes to new item
        (*head)->previous = item;
    }
}

//deletes an item from head and returns a pointer to the deleted item
queueElement *DelQueue(queueElement **head){
    
}








#endif //OS1_Q_H
