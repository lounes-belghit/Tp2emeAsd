#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char firstName[50];
    char lastName[50];
    char phoneNumber[15];
    char email[50];
} Contact;

// Function prototypes
void addContact(Contact** contacts, int* size);
void searchByName(Contact* contacts, int size, const char* name, int index);
void quickSort(Contact* contacts, int low, int high);
int partition(Contact* contacts, int low, int high);
void displayContacts(Contact* contacts, int size);
void deleteContact(Contact** contacts, int* size, int index);
int menu();

// Main function
int main() {
    Contact* contacts = NULL;
    int size = 0;
    int choice, index;
    char name[50];

    while (1) {
        choice = menu();

        switch (choice) {
            case 1:
                addContact(&contacts, &size);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                printf("Search Results:\n");
                searchByName(contacts, size, name, 0);
                break;
            case 3:
                quickSort(contacts, 0, size - 1);
                displayContacts(contacts, size);
                break;
            case 4:
                printf("Enter the index of the contact to delete (0 to %d): ", size - 1);
                scanf("%d", &index);
                if (index >= 0 && index < size) {
                    deleteContact(&contacts, &size, index);
                    printf("Contact deleted.\n");
                } else {
                    printf("Invalid index.\n");
                }
                break;
            case 5:
                free(contacts);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

// Menu function
int menu() {
    int choice;
    printf("\nContact Management System\n");
    printf("1. Add New Contact\n");
    printf("2. Search Contact by Name\n");
    printf("3. Sort and Display All Contacts by Last Name\n");
    printf("4. Delete Contact by Index\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    return choice;
}

// Add a new contact
void addContact(Contact** contacts, int* size) {
    *contacts = realloc(*contacts, (*size + 1) * sizeof(Contact));//u can not use this if u had located the memory in the main function 
    if (*contacts == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter details for new contact:\n");
    printf("First Name: ");
    scanf("%s", (*contacts)[*size].firstName);
    printf("Last Name: ");
    scanf("%s", (*contacts)[*size].lastName);
    printf("Phone Number: ");
    scanf("%s", (*contacts)[*size].phoneNumber);
    printf("Email: ");
    scanf("%s", (*contacts)[*size].email);

    (*size)++;
}

// Recursive search function by name
void searchByName(Contact* contacts, int size, const char* name, int index) {
    if (index >= size) {
        return;
    }

    if (strstr(contacts[index].firstName, name) || strstr(contacts[index].lastName, name)) {
        printf("Contact Found: %s %s, Phone: %s, Email: %s\n",
               contacts[index].firstName, contacts[index].lastName,
               contacts[index].phoneNumber, contacts[index].email);
    }

    searchByName(contacts, size, name, index + 1);
}

// Recursive QuickSort function to sort contacts by last name
void quickSort(Contact* contacts, int low, int high) {
    if (low < high) {
        int pi = partition(contacts, low, high);

        quickSort(contacts, low, pi - 1);
        quickSort(contacts, pi + 1, high);
    }
}

// Partition function for QuickSort
int partition(Contact* contacts, int low, int high) {
    Contact pivot = contacts[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(contacts[j].lastName, pivot.lastName) < 0 ||
            (strcmp(contacts[j].lastName, pivot.lastName) == 0 &&
             strcmp(contacts[j].firstName, pivot.firstName) < 0)) {
            i++;
            Contact temp = contacts[i];
            contacts[i] = contacts[j];
            contacts[j] = temp;
        }
    }
    Contact temp = contacts[i + 1];
    contacts[i + 1] = contacts[high];
    contacts[high] = temp;
    return i + 1;
}

// Display all contacts
void displayContacts(Contact* contacts, int size) {
    printf("\nSorted Contacts by Last Name:\n");
    for (int i = 0; i < size; i++) {
        printf("%s %s, Phone: %s, Email: %s\n",
               contacts[i].firstName, contacts[i].lastName,
               contacts[i].phoneNumber, contacts[i].email);
    }
}

// Delete contact by index
void deleteContact(Contact** contacts, int* size, int index) {
    for (int i = index; i < *size - 1; i++) {
        (*contacts)[i] = (*contacts)[i + 1];
    }

    *contacts = realloc(*contacts, (*size - 1) * sizeof(Contact));
    if (*contacts == NULL && *size > 1) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }

    (*size)--;
}
