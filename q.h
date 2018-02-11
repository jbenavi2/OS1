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

    queueElement *tmp = *head;  //return temp after head is deleted

    //check if queue is already empty
    if (*head == NULL){
        return NULL;
    }

    //if there is only one element in the queue
    //which happens only if the element points to itself
    if ((*head)->next == *head && (*head)->previous == *head){
        *head = NULL;

    }
    //more than one element
    else{
        //previous pointer of element after head points to the last element
        (*head)->next->previous = (*head)->previous;

        //next pointer of last element points to element after head
        (*head)->previous->next = (*head)->next;

        //make element after head the new head
        (*head) = (*head)->next;
    }

    return tmp;

}

//Moves the header pointer to the next element in the queue
void RotateQ(queueElement **head){
    (*head) = (*head)->next;
}






#endif //OS1_Q_H
