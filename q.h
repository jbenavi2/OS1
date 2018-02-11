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
    queueElement *item = malloc(sizeof(queueElement));
    return item;
}













#endif //OS1_Q_H
