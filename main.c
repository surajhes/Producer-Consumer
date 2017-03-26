#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
#define LIMIT 10
#define ITERATIONS 100

int array[BUFFER_SIZE];

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int count = 0;

void* produce(void* arg){
    printf("\n Inside producer");
    int i =0,iterations = 0;
    while (iterations < ITERATIONS){
        pthread_mutex_lock(&mutex);
        while (count == LIMIT){
            pthread_cond_wait(&cond,&mutex);
        }
        while(i < LIMIT){
            array[i] = rand();
            printf("\nProduced : %d",array[i]);
            i++;
            count++;
        }
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        printf("\n Produced Iteration %d",iterations);
        iterations++;
        i = 0;
    }
}

void* consume(void* arg){
    printf("\n Inside Consumer");
    int i = 0,iterations = 0;
    while (iterations < ITERATIONS){
        pthread_mutex_lock(&mutex);
        while (count == 0){
            pthread_cond_wait(&cond,&mutex);
        }
        while(i < LIMIT){
            printf("\n Consuming : %d",array[i++]);
        }
        count = 0;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        printf("\n Consumed Iteration %d",iterations);
        iterations++;
        i = 0;
    }
}


void main(){
    pthread_t producer,consumer;
    printf("\nCreating threads");
    pthread_create(&producer,NULL,produce,NULL);
    pthread_create(&consumer,NULL,consume,NULL);
    pthread_join(producer,NULL);
    pthread_join(consumer,NULL);
    printf("\n Exiting main");
}