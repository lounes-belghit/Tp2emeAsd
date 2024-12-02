#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void Enfiler(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int Defiler(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

int TeteFile(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

bool FileVide(Queue* q) {
    return q->front == NULL;
}

int main() {
    Queue q = {NULL, NULL};

    Enfiler(&q, 5);
    Enfiler(&q, 2);
    Enfiler(&q, 3);
    Enfiler(&q, -4);
    Enfiler(&q, 7);
    Enfiler(&q, 8);

    while (!FileVide(&q)) {
        printf("%d\n", Defiler(&q));
    }

    return 0;
}