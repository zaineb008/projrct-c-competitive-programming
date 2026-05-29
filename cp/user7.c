#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *gauche;
    struct Noeud *droite;
} Noeud;

Noeud* creerNoeud(int valeur) {
    Noeud* nouveauNoeud = malloc(sizeof(Noeud));
    nouveauNoeud->valeur = valeur;
    nouveauNoeud->gauche = NULL;
    nouveauNoeud->droite = NULL;
    return nouveauNoeud;
}

Noeud* inserer(Noeud* racine, int valeur) {
    if (!racine) return creerNoeud(valeur);
    if (valeur < racine->valeur)
        racine->gauche = inserer(racine->gauche, valeur);
    else
        racine->droite = inserer(racine->droite, valeur);
    return racine;
}

void enordre(Noeud* racine) {
    if (!racine) return;
    enordre(racine->gauche);
    printf("%d ", racine->valeur);
    enordre(racine->droite);
}

int compterNoeuds(Noeud* racine) {
    if (!racine) return 0;
    return 1 + compterNoeuds(racine->gauche) + compterNoeuds(racine->droite);
}

int trouvemin(Noeud* racine) {
    while (racine->gauche) racine = racine->gauche;
    return racine->valeur;
}

int trouvemax(Noeud* racine) {
    while (racine->droite) racine = racine->droite;
    return racine->valeur;
}

int main() {
    Noeud* racine = NULL;

    int valeur;
    while (scanf("%d", &valeur) == 1) {
        racine = inserer(racine, valeur);
    }

    // 1) In-order trié
    enordre(racine);
    printf("\n");

    // 2) nombre de noeuds
    printf("%d\n", compterNoeuds(racine));

    // 3) min
    printf("%d\n", trouvemin(racine));

    // 4) max
    printf("%d\n", trouvemax(racine));

    return 0;
}
