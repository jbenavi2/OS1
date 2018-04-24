/*
 * Javier Benavides
 * CSE 330 Project 3
 * Due 4/23/18
 */




#include <stdio.h>
#include <unistd.h>
#include "sem.h"
#include "threads.h"


int rc, wc, rwc, wwc = 0;
Semaphore *R_sem, *W_sem, *mutex;

void Reader_1(){
    while(1){
        P(mutex);
        if(wwc > 0 || wc > 0){
            rwc++;
            V(mutex);
            P(R_sem);
            P(mutex);
            rwc--;
        }
        rc++;
        V(mutex);

        //SP READ

        printf("I'm reading 1\n");

        sleep(1);

        P(mutex);
        rc--;
        if(rc == 0 && wwc > 0){
            V(W_sem);
        }
        V(mutex);
    }
}

void Reader_2(){
    while(1){
        P(mutex);
        if(wwc > 0 || wc > 0){
            rwc++;
            V(mutex);
            P(R_sem);
            P(mutex);
            rwc--;
        }
        rc++;
        V(mutex);

        //SP READ

        printf("I'm reading 2\n");

        sleep(1);

        P(mutex);
        rc--;
        if(rc == 0 && wwc > 0){
            V(W_sem);
        }
        V(mutex);
    }
}

void Reader_3(){
    while(1){
        P(mutex);
        if(wwc > 0 || wc > 0){
            rwc++;
            V(mutex);
            P(R_sem);
            P(mutex);
            rwc--;
        }
        rc++;
        V(mutex);

        //SP READ

        printf("I'm reading 3\n");

        sleep(1);

        P(mutex);
        rc--;
        if(rc == 0 && wwc > 0){
            V(W_sem);
        }
        V(mutex);
    }
}

void Writer_1(){
    while(1){
        P(mutex);
        if(rc > 0 || wc > 0){
            wwc++;
            V(mutex);
            P(W_sem);
            P(mutex);
            wwc--;
        }
        wc++;
        V(mutex);

        //SP WRITE

        printf("I'm writing 1\n");

        sleep(1);

        P(mutex);
        wc--;
        if(rwc > 0){
            int i;
            for(i = 0; i < rwc; i++){
                V(R_sem);
            }
        }
        else if(wwc > 0){
            V(W_sem);
        }
        V(mutex);
    }
}

void Writer_2(){
    while(1){
        P(mutex);
        if(rc > 0 || wc > 0){
            wwc++;
            V(mutex);
            P(W_sem);
            P(mutex);
            wwc--;
        }
        wc++;
        V(mutex);

        //SP WRITE

        printf("I'm writing 2\n");

        sleep(1);

        P(mutex);
        wc--;
        if(rwc > 0){
            int i;
            for(i = 0; i < rwc; i++){
                V(R_sem);
            }
        }
        else if(wwc > 0){
            V(W_sem);
        }
        V(mutex);
    }
}

int main()
{
    runQ = InitQueue();
    mutex = InitSem(1);
    R_sem = InitSem(0);
    W_sem = InitSem(0);



    start_thread(Writer_1);
    start_thread(Writer_2);
    start_thread(Reader_1);
    start_thread(Reader_2);
    start_thread(Reader_3);

    run();


    return 0;
}






