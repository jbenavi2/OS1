#include <stdio.h>
#include <string.h>
#include "q.h"


int main() {




    queueElement **head;
    head = malloc(sizeof(queueElement));
    int i;

    InitQueue(head);

    queueElement *item;

    for (i = 0; i < 10; i++){
        item = NewItem();
        item->payload = i;
        AddQueue(head, item);
    }

    PrintQ(*head);

    for (i = 0; i < 5; i++){
        item = DelQueue(head);
        printf("Item deleted %d\n", item->payload);
    }

    RotateQ(head);

    item = DelQueue(head);

    printf("item Deleted %d\n", item->payload);

    PrintQ(*head);

    RotateQ(head);

    PrintQ(*head);

    item = NewItem();
    item->payload= 15;
    AddQueue(head, item);

    PrintQ(*head);

    RotateQ(head);

    PrintQ(*head);


    printf("hello, world");
    return 0;
}