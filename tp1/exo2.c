#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numeroRue;
    char nomRue[50];
    char nomVille[50];
    char codePostal[10];
} Adresse;

typedef struct {
    char nom[50];
    char prenom[50];
    float moyenne;
    Adresse adresse;
} Etudiant;

void saisirEtudiant(Etudiant *etudiant) {
    printf("Saisir le nom: ");
    scanf("%s", etudiant->nom);
    printf("Saisir le prenom: ");
    scanf("%s", etudiant->prenom);
    printf("Saisir la moyenne: ");
    scanf("%f", &etudiant->moyenne);
    printf("Saisir le numero de rue: ");
    scanf("%d", &etudiant->adresse.numeroRue);
    printf("Saisir le nom de la rue: ");
    scanf("%s", &etudiant->adresse.nomRue);

    printf("Saisir le nom de la ville: ");
    scanf("%s", etudiant->adresse.nomVille);
    printf("Saisir le code postal: ");
    scanf("%s", etudiant->adresse.codePostal);
}

void afficherEtudiant(Etudiant etudiant) {
    printf("Nom: %s\n", etudiant.nom);
    printf("Prenom: %s\n", etudiant.prenom);
    printf("Moyenne: %.2f\n", etudiant.moyenne);
    printf("Adresse: %d, %s, %s, %s\n", etudiant.adresse.numeroRue, etudiant.adresse.nomRue, etudiant.adresse.nomVille, etudiant.adresse.codePostal);
}

int main() {
    int n;
    printf("Saisir le nombre d'etudiants: ");
    scanf("%d", &n);

    Etudiant *etudiants = (Etudiant *)malloc(n * sizeof(Etudiant));

    for (int i = 0; i < n; i++) {
        printf("Saisir les informations de l'etudiant %d:\n", i + 1);
        saisirEtudiant(&etudiants[i]);
    }

    printf("\nAffichage des informations des etudiants:\n");
    for (int i = 0; i < n; i++) {
        printf("Etudiant %d:\n", i + 1);
        afficherEtudiant(etudiants[i]);
    }

    free(etudiants);
    return 0;
}