#include <stdio.h>
#include <stdlib.h>

typedef struct boule {
    int numb;
    struct boule* suiv;
} boule;

typedef struct file {
    boule* T; // tête
    boule* Q; // queue
} file;

// initialement le stock des boules est vide
void stock_vide(file *f) {
    f->T = NULL;
    f->Q = NULL;
}

int est_vide(file *f) {
    return (f->T == NULL && f->Q == NULL);
}

// lors du jeu les boules tombent dans les trous
void enfiler(file *f, int n) {
    boule *p;
    p=(boule*)malloc(sizeof(boule));
    p->suiv = NULL;
    p->numb = n;

    if (!est_vide(f)) {
        f->Q->suiv = p;
        f->Q = p;
    } else {
        f->T = p;
        f->Q = p;
    }
}

// à la fin du jeu on fait sortir les boules
int sortie_boules(file *f) {
    boule *q;
    int e;

    if (!est_vide(f)) {
        q = f->T;
        e = q->numb;
        f->T = q->suiv;
        free(q);

        // si la file devient vide
        if (f->T == NULL) {
            f->Q = NULL;
        }
        return e;
    } else {
        printf("Le stock des boules est vide, aucune boule n'a été entrée.\n");
        return -1; // valeur indiquant qu’il n’y a rien
    }
}
// afficher la file
void afficher(file *f) {
    boule* p;
    p = f->T;
    while (p != NULL) {
        printf("%d ", p->numb);
        p = p->suiv;
    }
    printf("\n");
}





int main() {
    file F;
    stock_vide(&F);

    int nb_boules_max=8, x, i = 0;
    printf("\n--- Début du remplissage de la file ---\n");

    // remplissage de la file avec contrainte : toutes les boules tombées
    while (i < nb_boules_max) {
        printf("Donner le numéro de la boule %d : ", i + 1);
        scanf("%d", &x);
        enfiler(&F, x);
        i++;
    }

    printf("\n--- Contenu de la file après remplissage ---\n");
    afficher(&F);

    printf("\n--- Sortie des boules ---\n");
    while (!est_vide(&F)) {
        printf("%d\n", sortie_boules(&F));
    }

    return 0;
}
