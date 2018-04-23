/*
 * Javier Benavides
 * CSE 330 Project 2
 * Due 4/2/18
 */




#include <stdio.h>
#include <unistd.h>
#include "sem.h"
#include "threads.h"


int rc, wc, rwc, wwc = 0;
Semaphore *R_sem, *W_sem, *mutex;

void Reader(){
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

        printf("I'm reading\n");

        sleep(1);

        P(mutex);
        rc--;
        if(rc == 0 && wwc > 0){
            V(W_sem);
        }
        V(mutex);
    }
}

void Writer(){
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

        printf("I'm writing\n");

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



    start_thread(Writer);
    start_thread(Writer);
    start_thread(Reader);
    start_thread(Reader);
    start_thread(Reader);

    run();


    return 0;
}






