/*
This program provides a possible solution for  readers writers problem using mutex and semaphore.
*/
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

sem_t wrt;//semaphore datatype
pthread_mutex_t mutex;//mutex datatype
int numreader=0;

int cnt=1;


void *writer(void *wno)
{
    sem_wait(&wrt);
    cnt = cnt*2;
    printf("Writer %d modified cnt to %d\n",*((int *)wno),cnt);
    sem_post(&wrt);
}

void *reader(void *rno)
{
    pthread_mutex_lock(&mutex);
    numreader++;
    if(numreader==1)
    {
        sem_wait(&wrt);

    }
    pthread_mutex_unlock(&mutex);
    printf("Reader %d : read cnt as %d\n",*((int*)rno),cnt);

    pthread_mutex_lock(&mutex);
    numreader--;
    if(numreader==0)
    {
        sem_post(&wrt);
    }
    pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_t read[10],write[5];
    pthread_mutex_init(&mutex,NULL);//ATTEMPTING initialised mutex to initialised mutex results in undefined behaviour
    sem_init(&wrt,0,1);/*sem_init(sem_t *sem,int pshared,unsigned int value)
    pshared : non zero value means the semaphore is shared between processes 
              A zero value means it is shared between threads
    unsigned int value : it value initializatio*/
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    for(int i = 0; i < 10; i++) {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);/* int pthread_create(pthread_t *new_threadID, const pthread_attr_t *attr,
        void*(*start function)(void*),void *argument);
        Arguments:
        1.pointer of the thread Id 
        2.Attributes to set the properties of thread :  for default-> NULL
        3.Function pointer to the function that thread will in parallel
        4.Arguments to be passed to function*/
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }

    for(int i = 0; i < 10; i++) {
        pthread_join(read[i], NULL); // accepts thread Id and a pointer to store the return value from thread: default-> NULL
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);// if in case you are destroying an locked mutex it will show an undefined behaviour error

    sem_destroy(&wrt);

    return 0;
    
}