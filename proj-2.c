/*
 * Javier Benavides
 * CSE 330 Project 2
 * Due 4/2/18
 */




#include <stdio.h>
#include <unistd.h>
#include "sem.h"
#include "threads.h"


int store[5];
int produce, consume = 0;
Semaphore *full, *empty, *consumerMutex, *producerMutex;


void Producer_1()
{
    while(1)
    {
        P(empty);
        P(producerMutex); // Begin critical section

        store[produce] = 1;
        produce = (produce + 1) % 5;

        printf("Producer 1:    \t");
        int i;
        for(i = 0; i < 5; i++){
            printf("%d\t", store[i]);
        }
        printf("\n");
        sleep(2);

        V(producerMutex); // End critical section
        V(full);
    }
}

void Producer_2()
{
    while(1)
    {
        P(empty);
        P(producerMutex); // Begin critical section

        store[produce] = 1;
        produce = (produce + 1) % 5;

        printf("Producer 2:    \t");
        int i;
        for(i = 0; i < 5; i++){
            printf("%d\t", store[i]);
        }
        printf("\n");
        sleep(2);

        V(producerMutex); // End critical section
        V(full);
    }
}

void Consumer_1()
{
    while(1)
    {
        P(full);
        P(consumerMutex); // Begin critical section

        store[consume] = 0;
        consume = (consume + 1) % 5;

        printf("Consumer 1:  \t");
        int i;
        for(i = 0; i < 5; i++){
            printf("%d\t", store[i]);
        }
        printf("\n");
        sleep(2);

        V(consumerMutex); // End critical section
        V(empty);
    }
}

void Consumer_2()
{
    while(1)
    {
        P(full);
        P(consumerMutex); // Begin critical section

        store[consume] = 0;
        consume = (consume + 1) % 5;

        printf("Consumer 2:  \t");
        int i;
        for(i = 0; i < 5; i++){
            printf("%d\t", store[i]);
        }
        printf("\n");
        sleep(2);

        V(consumerMutex); // End critical section
        V(empty);
    }
}



int main()
{
    runQ = InitQueue();
    full = InitSem(0);
    empty = InitSem(5);
    producerMutex = InitSem(1);
    consumerMutex = InitSem(1);

    int i;
    for (i = 0; i < 5; i++) {
        store[i] = 0;
    }

    start_thread(Producer_1);
    start_thread(Producer_2);
    start_thread(Consumer_1);
    start_thread(Consumer_2);

    run();


    return 0;
}






