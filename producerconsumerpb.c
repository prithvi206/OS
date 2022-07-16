/*
This program provides a possible solution for producer-consumer problem using mutex and semaphore.
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define Maxitems 5
#define Buffersize 5


sem_t empty;//semaphore datatype
sem_t full;//semaphore datatype

int in =0;
int out=0;

int buffer[Buffersize];
pthread_mutex_t mutex;//mutex datatype


void *producer(void *pno)
{
    int item;
    for(int i=0;i<Maxitems;i++)
    {
        item = rand();
        sem_wait(&empty);//decrement the value of empty as a slot is filled by producer
        pthread_mutex_lock(&mutex);//lock mutex
        buffer[in]=item;
        printf("Producer %d :INSERT Items %d at %d\n",*((int*)pno),buffer[in],in);
        in= (in+1)%Buffersize;
        pthread_mutex_unlock(&mutex);//unlock mutex
        sem_post(&full);//increment the full as a slot is filled

    }
}

void *consumer(void *con)
{
    for(int i=0;i<Maxitems;i++)
    {
        sem_wait(&full);//decrement the value of full as it is consumed now
        pthread_mutex_lock(&mutex);//lock mutex
        int item = buffer[out];
        printf("Consumer %d : REMOVE item %d from %d\n",*((int *)con),item,out);
        out= (out+1)%Buffersize;
        pthread_mutex_unlock(&mutex);//unlock mutex
        sem_post(&empty);//increment the value of empty as the a slot is freed
    }
}

int main()
{
    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex,NULL);//ATTEMPTING initialised mutex to initialised mutex results in undefined behaviour
    sem_init(&empty,0,Buffersize);/*sem_init(sem_t *sem,int pshared,unsigned int value)
    pshared : non zero value means the semaphore is shared between processes 
              A zero value means it is shared between threads
    unsigned int value : it value initializatio*/

    sem_init(&full,0,0);

    int a[5]={1,2,3,4,5};

    for(int i=0;i<5;i++)
    {
        pthread_create(&pro[i],NULL,(void*)producer,(void*)&a[i]);/* int pthread_create(pthread_t *new_threadID, const pthread_attr_t *attr,
        void*(*start function)(void*),void *argument);
        Arguments:
        1.pointer of the thread Id 
        2.Attributes to set the properties of thread :  for default-> NULL
        3.Function pointer to the function that thread will in parallel
        4.Arguments to be passed to function*/
    }
     for(int i=0;i<5;i++)
    {
        pthread_create(&con[i],NULL,(void*)consumer,(void*)&a[i]);

    }
     for(int i=0;i<5;i++)
    {
        pthread_join(pro[i],NULL);
        // accepts thread Id and a pointer to store the return value from thread: default-> NULL
    }
      for(int i=0;i<5;i++)
    {
        pthread_join(con[i],NULL);
    }

    pthread_mutex_destroy(&mutex);// if in case you are destroying an locked mutex it will show an undefined behaviour error
    sem_destroy(&full);
    sem_destroy(&empty);
    return 0;
}
