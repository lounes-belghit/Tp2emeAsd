#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Déclaration de la structure Pile
typedef struct {
    int *elements;    // Tableau dynamique pour stocker les éléments
    int sommet;       // Indice du sommet
    int capacite;     // Capacité maximale de la pile
} Pile;

// Fonction pour initialiser une pile
Pile* creerPile(int capacite) {
    Pile *pile = (Pile*)malloc(sizeof(Pile));
    pile->capacite = capacite;
    pile->sommet = -1;
    pile->elements = (int*)malloc(capacite * sizeof(int));
    return pile;
}

// Fonction pour vérifier si la pile est vide
bool pileVide(Pile *pile) {
    return pile->sommet == -1;
}

// Fonction pour empiler un élément
void empiler(Pile *pile, int valeur) {
    if (pile->sommet == pile->capacite - 1) {
        printf("Pile pleine, impossible d'empiler %d.\n", valeur);
        return;
    }
    pile->elements[++(pile->sommet)] = valeur;
}

// Fonction pour dépiler un élément
int depiler(Pile *pile) {
    if (pileVide(pile)) {
        printf("Pile vide, impossible de dépiler.\n");
        exit(EXIT_FAILURE);
    }
    return pile->elements[(pile->sommet)--];
}

// Fonction pour obtenir l'élément au sommet de la pile
int sommetPile(Pile *pile) {
    if (pileVide(pile)) {
        printf("Pile vide, aucun sommet disponible.\n");
        exit(EXIT_FAILURE);
    }
    return pile->elements[pile->sommet];
}

// Fonction principale
int main() {
    // Création d'une pile de capacité 10
    Pile *pile = creerPile(10);

    // Empiler les valeurs 5, 2, 3, -4, 7 et 8
    empiler(pile, 5);
    empiler(pile, 2);
    empiler(pile, 3);
    empiler(pile, -4);
    empiler(pile, 7);
    empiler(pile, 8);

    // Dépiler et afficher les éléments
    int i = 0;
    printf("Contenu de pile : ");
    while (!pileVide(pile)) {
        if(i!=0){
        printf("-> %d", depiler(pile));}
        else{
        printf("%d", depiler(pile));}
        i++;
    }
    printf("\n");

    // Libérer la mémoire
    free(pile->elements);
    free(pile);

    return 0;
}
