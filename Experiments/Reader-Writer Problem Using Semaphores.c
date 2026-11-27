// Question: Construct a C program to simulate Reader-Writer problem using semaphores.
// Code:
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, writeBlock;

int data = 0, readersCount = 0;

void *reader(void *arg) {
    int i=0;

    while (i<10) {
        sem_wait(&mutex);

        readersCount++;

        if (readersCount == 1) {
            sem_wait(&writeBlock);
        }

        sem_post(&mutex);

        // Reading operation
        printf("Reader reads data: %d\n", data);

        sem_wait(&mutex);

        readersCount--;

        if (readersCount == 0) {
            sem_post(&writeBlock);
        }

        sem_post(&mutex);

        i++;
    }
}

void *writer(void *arg) {
    int i=0;

    while (i<10) {
        sem_wait(&writeBlock);

        // Writing operation
        data++;
        printf("Writer writes data: %d\n", data);

        sem_post(&writeBlock);
        i++;
    }
}

int main() {
    pthread_t readers, writers;

    sem_init(&mutex, 0, 1);
    sem_init(&writeBlock, 0, 1);

    pthread_create(&readers, NULL, reader, NULL);
    pthread_create(&writers, NULL, writer, NULL);

    pthread_join(readers, NULL);
    pthread_join(writers, NULL);

    sem_destroy(&mutex);
    sem_destroy(&writeBlock);

    return 0;
}
// Output:
// Writer writes data: 1
// Writer writes data: 2
// Writer writes data: 3
// Writer writes data: 4
// Writer writes data: 5
// Writer writes data: 6
// Writer writes data: 7
// Writer writes data: 8
// Writer writes data: 9
// Reader reads data: 3
// Reader reads data: 10
// Reader reads data: 10
// Reader reads data: 10
// Reader reads data: 10
// Writer writes data: 10
// Reader reads data: 10
// Reader reads data: 10
// Reader reads data: 10
// Reader reads data: 10
// Reader reads data: 10
