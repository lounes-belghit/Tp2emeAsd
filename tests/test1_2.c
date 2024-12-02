#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for inventory items
typedef struct {
    char itemCode[10];
    char itemName[50];
    int quantity;
    float price;
} Item;

// Function to populate inventory items
void addItems(Item *inventory, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for item %d:\n", i + 1);
        printf("Item Code: ");
        scanf("%s", inventory[i].itemCode);
        printf("Item Name: ");
        getchar();  // to consume the newline character left by scanf
        fgets(inventory[i].itemName, 50, stdin);
        inventory[i].itemName[strcspn(inventory[i].itemName, "\n")] = '\0';  // Remove newline from fgets input
        printf("Quantity: ");
        scanf("%d", &inventory[i].quantity);
        printf("Price: ");
        scanf("%f", &inventory[i].price);
        printf("\n");
    }
}

// Recursive function to search for an item by item code
Item* searchItem(Item *inventory, int start, int end, const char *code) {
    if (start > end) {
        return NULL; // Item not found
    }

    int mid = (start + end) / 2;
    
    // Compare item codes to find the match
    if (strcmp(inventory[mid].itemCode, code) == 0) {
        return &inventory[mid]; // Return the pointer to the matching item
    } else if (strcmp(inventory[mid].itemCode, code) < 0) {
        return searchItem(inventory, mid + 1, end, code); // Search in the right half
    } else {
        return searchItem(inventory, start, mid - 1, code); // Search in the left half
    }
}

// Function to swap two items (used in quick sort)
void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quick sort
int partition(Item *inventory, int low, int high) {
    float pivot = inventory[high].price;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (inventory[j].price < pivot || (inventory[j].price == pivot && strcmp(inventory[j].itemName, inventory[high].itemName) < 0)) {
            i++;
            swap(&inventory[i], &inventory[j]);
        }
    }
    swap(&inventory[i + 1], &inventory[high]);
    return i + 1;
}

// Recursive quick sort function
void quickSort(Item *inventory, int low, int high) {
    if (low < high) {
        int pi = partition(inventory, low, high);
        quickSort(inventory, low, pi - 1);
        quickSort(inventory, pi + 1, high);
    }
}

// Function to display the inventory
void displayInventory(Item *inventory, int n) {
    printf("Item Code\tItem Name\tQuantity\tPrice\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%s\t\t%d\t\t%.2f\n", inventory[i].itemCode, inventory[i].itemName, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int n;
    printf("Enter the number of items in the inventory: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the inventory
    Item *inventory = (Item*)malloc(n * sizeof(Item));
    if (inventory == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Add items to the inventory
    addItems(inventory, n);

    // Menu for user operations
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add item details\n");
        printf("2. Search for an item by code\n");
        printf("3. Sort and display all items by price\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the number of items to add: ");
                int new_items;
                scanf("%d", &new_items);
                inventory = realloc(inventory, (n + new_items) * sizeof(Item));
                addItems(inventory + n, new_items);
                n += new_items;
                break;

            case 2:
                {
                    char code[10];
                    printf("\nEnter the item code to search: ");
                    scanf("%s", code);
                    Item *foundItem = searchItem(inventory, 0, n - 1, code);
                    if (foundItem) {
                        printf("\nItem found:\n");
                        printf("Item Code: %s\n", foundItem->itemCode);
                        printf("Item Name: %s\n", foundItem->itemName);
                        printf("Quantity: %d\n", foundItem->quantity);
                        printf("Price: %.2f\n", foundItem->price);
                    } else {
                        printf("Item not found!\n");
                    }
                }
                break;

            case 3:
                quickSort(inventory, 0, n - 1);
                printf("\nSorted Inventory:\n");
                displayInventory(inventory, n);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    // Free the dynamically allocated memory
    free(inventory);

    return 0;
}
