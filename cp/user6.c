#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Noeud {
    int valeur;
    struct Noeud* suivant;
    struct Noeud* precedent;
} Noeud;


typedef struct Liste {
    Noeud* debut;
    Noeud* fin;
} Liste;


typedef struct CellulePile {
    Noeud* pointeurNoeud;
    struct CellulePile* suivant;
} CellulePile;


typedef struct Pile {
    CellulePile* sommet;
} Pile;



void initialiserListe(Liste* L) {
    L->debut = NULL;
    L->fin = NULL;
}

Noeud* ajouterFin(Liste* L, int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->valeur = valeur;
    nouveau->suivant = NULL;
    nouveau->precedent = L->fin;

    if (L->fin != NULL)
        L->fin->suivant = nouveau;

    L->fin = nouveau;
    if (L->debut == NULL)
        L->debut = nouveau;

    return nouveau;
}

void supprimerNoeud(Liste* L, Noeud* n) {
    if (n == NULL) return;

    if (n->precedent != NULL)
        n->precedent->suivant = n->suivant;
    else
        L->debut = n->suivant;

    if (n->suivant != NULL)
        n->suivant->precedent = n->precedent;
    else
        L->fin = n->precedent;

    free(n);
}

void afficherListe(Liste* L) {
    Noeud* temp = L->debut;
    while (temp != NULL) {
        printf("%d ", temp->valeur);
        temp = temp->suivant;
    }
    printf("\n");
}



void initialiserPile(Pile* P) {
    P->sommet = NULL;
}

void empiler(Pile* P, Noeud* n) {
    CellulePile* c = (CellulePile*)malloc(sizeof(CellulePile));
    c->pointeurNoeud = n;
    c->suivant = P->sommet;
    P->sommet = c;
}

Noeud* depiler(Pile* P) {
    if (P->sommet == NULL) return NULL;

    CellulePile* temp = P->sommet;
    Noeud* adresse = temp->pointeurNoeud;
    P->sommet = P->sommet->suivant;
    free(temp);

    return adresse;
}



int main() {
    int nbInstructions;
    scanf("%d", &nbInstructions);

    Liste historique;
    Pile pileAnnuler;

    initialiserListe(&historique);
    initialiserPile(&pileAnnuler);

    char commande[15];
    int valeur;

    for (int i = 0; i < nbInstructions; i++) {
        scanf("%s", commande);

        if (strcmp(commande, "ADD") == 0) {
            scanf("%d", &valeur);
            Noeud* adresse = ajouterFin(&historique, valeur);
            empiler(&pileAnnuler, adresse);

        } else if (strcmp(commande, "UNDO") == 0) {
            Noeud* derniereAction = depiler(&pileAnnuler);
            supprimerNoeud(&historique, derniereAction);

        } else if (strcmp(commande, "PRINT") == 0) {
            afficherListe(&historique);
        }
    }

    return 0;
}