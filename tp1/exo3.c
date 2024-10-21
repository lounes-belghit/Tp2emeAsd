#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define CODE_LENGTH 10
#define NAME_LENGTH 100

typedef struct {
    char code[CODE_LENGTH];
    char name[NAME_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Entrepôt plein, impossible d'ajouter plus de produits.\n");
        return;
    }

    char code[CODE_LENGTH];
    char name[NAME_LENGTH];

    printf("Entrez le code produit: ");
    scanf("%s", code);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].code, code) == 0) {
            printf("Produit avec ce code existe déjà.\n");
            return;
        }
    }

    printf("Entrez l'intitulé: ");
    scanf(" %[^\n]", name);

    strcpy(products[productCount].code, code);
    strcpy(products[productCount].name, name);
    products[productCount].quantity = 0;
    productCount++;
    printf("Produit ajouté avec succès.\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("Aucun produit dans l'entrepôt.\n");
        return;
    }

    for (int i = 0; i < productCount; i++) {
        printf("Code: %s, Intitulé: %s, Quantité: %d\n", products[i].code, products[i].name, products[i].quantity);
    }
}

void deleteProduct() {
    char code[CODE_LENGTH];
    printf("Entrez le code produit à supprimer: ");
    scanf("%s", code);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].code, code) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("Produit supprimé avec succès.\n");
            return;
        }
    }
    printf("Produit non trouvé.\n");
}

void buyProduct() {
    char code[CODE_LENGTH];
    int quantity;
    printf("Entrez le code produit: ");
    scanf("%s", code);
    printf("Entrez la quantité achetée: ");
    scanf("%d", &quantity);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].code, code) == 0) {
            products[i].quantity += quantity;
            printf("Produit mis à jour avec succès.\n");
            return;
        }
    }
    printf("Produit non trouvé.\n");
}

void sellProduct() {
    char code[CODE_LENGTH];
    int quantity;
    printf("Entrez le code produit: ");
    scanf("%s", code);
    printf("Entrez la quantité vendue: ");
    scanf("%d", &quantity);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].code, code) == 0) {
            if (products[i].quantity < quantity) {
                printf("Quantité insuffisante en stock.\n");
                return;
            }
            products[i].quantity -= quantity;
            printf("Produit mis à jour avec succès.\n");
            return;
        }
    }
    printf("Produit non trouvé.\n");
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un produit\n");
        printf("2. Afficher la liste de produits\n");
        printf("3. Supprimer un produit\n");
        printf("4. Acheter un produit\n");
        printf("5. Vendre un produit\n");
        printf("6. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                buyProduct();
                break;
            case 5:
                sellProduct();
                break;
            case 6:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choice != 6);

    return 0;
}