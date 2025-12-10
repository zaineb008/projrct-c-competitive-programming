#include <stdio.h>


void lire_combinaison(int tableau[]);
int nb_bien_positions(int code_secret[], int proposition[]);
int nb_mal_positions(int code_secret[], int proposition[]);
void jeu_mastermind();


void lire_combinaison(int tableau[]) {
    for(int indice = 0; indice < 4; indice++)
        scanf("%d", &tableau[indice]);
}


int nb_bien_positions(int code_secret[], int proposition[]) {
    int compteur = 0;
    for(int k = 0; k < 4; k++)
        if(code_secret[k] == proposition[k])
            compteur++;
    return compteur;
}


int nb_mal_positions(int code_secret[], int proposition[]) {
    int compteur = 0;
    for(int a = 0; a < 4; a++){
        for(int b = 0; b < 4; b++){
            if(a != b && proposition[a] == code_secret[b])
                compteur++;
        }
    }
    return compteur;
}


void jeu_mastermind() {

    int combinaison_secrete[4];
    int tentative[4];

    lire_combinaison(combinaison_secrete);
    lire_combinaison(tentative);

    int corrects = nb_bien_positions(combinaison_secrete, tentative);
    int mal_places = nb_mal_positions(combinaison_secrete, tentative);

    printf("%d %d\n", corrects, mal_places);
}

int main() {
    jeu_mastermind();
    return 0;
}