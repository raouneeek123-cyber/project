#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int customerNumber;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;

void initQueue(Queue* q){
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue q){
    return q.front == NULL;
}

void enqueue(Queue* q, int number){
    Node* n = malloc(sizeof(Node));
    if (n == NULL){
        printf("memory error\n");
        return;
    }
    n->customerNumber = number;
    n->next = NULL;
    if (isEmpty(*q)){
        q->front = n;
    } else {
        q->rear->next = n;
    }
    q->rear = n;
}

int dequeue(Queue* q){
    if(isEmpty(*q)){
        printf("Queue is empty.\n");
        return -1;
    }
    Node* t = q->front;
    int number = t->customerNumber;
    q->front = t->next;
    if(q->front == NULL){
        q->rear = NULL;
    }
    free(t);
    return number;
}

int peek(Queueq){
    if(isEmpty(q)){
        return -1;
    }
    return q.front->customerNumber;
}
