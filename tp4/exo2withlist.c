#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Définition du nœud de la liste
typedef struct Noeud {
    int valeur;
    struct Noeud *suivant;
} Noeud;

// Définition de la pile
typedef struct {
    Noeud *sommet; // Pointeur vers le sommet de la pile
} Pile;

// Fonction pour créer une nouvelle pile
Pile* creerPile() {
    Pile *pile = (Pile*)malloc(sizeof(Pile));
    pile->sommet = NULL;
    return pile;
}

// Fonction pour vérifier si la pile est vide
bool pileVide(Pile *pile) {
    return pile->sommet == NULL;
}

// Fonction pour empiler un élément
void empiler(Pile *pile, int valeur) {
    Noeud *nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
    nouveauNoeud->valeur = valeur;
    nouveauNoeud->suivant = pile->sommet;
    pile->sommet = nouveauNoeud;
}

// Fonction pour dépiler un élément
int depiler(Pile *pile) {
    if (pileVide(pile)) {
        printf("Pile vide, impossible de dépiler.\n");
        exit(EXIT_FAILURE);
    }
    Noeud *noeudSupprime = pile->sommet;
    int valeur = noeudSupprime->valeur;
    pile->sommet = noeudSupprime->suivant;
    free(noeudSupprime);
    return valeur;
}

// Fonction pour obtenir l'élément au sommet de la pile
int sommetPile(Pile *pile) {
    if (pileVide(pile)) {
        printf("Pile vide, aucun sommet disponible.\n");
        exit(EXIT_FAILURE);
    }
    return pile->sommet->valeur;
}

// Fonction principale
int main() {
    // Création de la pile
    Pile *pile = creerPile();

    // Empiler les valeurs 5, 2, 3, -4, 7 et 8
    empiler(pile, 5);
    empiler(pile, 2);
    empiler(pile, 3);
    empiler(pile, -4);
    empiler(pile, 7);
    empiler(pile, 8);

    // Dépiler et afficher les éléments
    printf("Contenu dépilé : ");
    while (!pileVide(pile)) {
        printf("%d ", depiler(pile));
    }
    printf("\n");

    // Libérer la mémoire
    free(pile);

    return 0;
}
