#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list from user input
Node* createList() {
    Node* head = NULL;
    Node* temp = NULL;
    int data;
    char choice;

    do {
        printf("Enter an integer: ");
        scanf("%d", &data);
        Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return head;
}

// Function to display the contents of the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to calculate the length of the list
int listLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Function to count the number of even values in the list
int countEvenValues(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

// Function to insert a new element at position k
void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    Node* list = createList();
    displayList(list);
    printf("Length of the list: %d\n", listLength(list));
    printf("Number of even values: %d\n", countEvenValues(list));

    int data, position;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    printf("Enter position to insert at: ");
    scanf("%d", &position);
    insertAtPosition(&list, data, position);
    displayList(list);

    return 0;
}