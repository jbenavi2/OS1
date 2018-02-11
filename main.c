#include <stdio.h>
#include <string.h>
#include "q.h"


int main() {


    queueElement **head;
    queueElement *item;
    queueElement *item2;
    queueElement *item3;

    head = malloc(sizeof(queueElement));

    InitQueue(head);



    item = NewItem();
    item->payload = 1;

    item2 = NewItem();
    item2->payload = 2;

    item3 = NewItem();
    item3->payload = 3;

    AddQueue(head, item);
    AddQueue(head, item2);
    AddQueue(head, item3);

    printf("%d\n", (*head)->payload);
    printf("%d\n", (*head)->next->payload);
    printf("%d\n", (*head)->next->next->payload);
    printf("%d\n", (*head)->next->next->next->payload);

    RotateQ(head);

    printf("%d\n", (*head)->payload);
    printf("%d\n", (*head)->next->payload);
    printf("%d\n", (*head)->next->next->payload);
    printf("%d\n", (*head)->next->next->next->payload);

    DelQueue(head);

    printf("%d\n", (*head)->payload);
    printf("%d\n", (*head)->next->payload);
    printf("%d\n", (*head)->next->next->payload);
    printf("%d\n", (*head)->next->next->next->payload);

    printf("hello, world");
    return 0;
}