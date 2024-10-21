#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nom[50];
    char prenom[50];
    char matricule[10];
} Etudiant;

void saisirEtudiant(Etudiant *etudiant) {
    printf("Nom: ");
    scanf("%s", etudiant->nom);
    printf("Prenom: ");
    scanf("%s", etudiant->prenom);
    printf("Matricule: ");
    scanf("%s", etudiant->matricule);
}

void afficherEtudiant(Etudiant etudiant) {
    printf("Nom: %s, Prenom: %s, Matricule: %s\n", etudiant.nom, etudiant.prenom, etudiant.matricule);
}

int main() {
    int n;
    printf("Entrez le nombre d'etudiants: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Le nombre d'etudiants doit etre superieur a 0.\n");
        return 1;
    }

    Etudiant *etudiants = (Etudiant *)malloc(n * sizeof(Etudiant));
    if (etudiants == NULL) {
        printf("Erreur d'allocation de memoire.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Saisie de l'etudiant %d:\n", i + 1);
        saisirEtudiant(&etudiants[i]);
    }

    printf("\nListe des etudiants:\n");
    for (int i = 0; i < n; i++) {
        afficherEtudiant(etudiants[i]);
    }

    free(etudiants);
    return 0;
}
