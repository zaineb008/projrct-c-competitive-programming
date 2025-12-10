#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Affichage des énoncés de chaque défi
void afficher_enonce(int choix) {
    printf("\n=== ENONCE DU DEFI ===\n");
    switch(choix) {
        case 1:
            printf(" =========Defi Le Compte est Bon ==============\n");
            printf("           - Objectif : Trouver une combinaison d'opérations pour atteindre un\n");
            printf("           nombre cible\n");
            printf("           - inputs: 6 entier et un entier cible ");
            printf("           - Sortie : Une séquence d'opérations valide (chaine de caractere ) dans l'ordre d'apparition dans le tableau ");
            printf("           - Exemple : Avec [2, 3, 5, 7, 10, 25] et cible 133 →(((((2+3)+25)*5)-7)-10) = 133\n");
            break;
        case 2:
            printf("=== Defi : Mastermind Algorithmique ===\n");

            printf("            Objectif :\n");
            printf("            Deviner une séquence secrète composée de 4 chiffres (entre 0 et 9).\n");

            printf("            Description du défi :\n");
            printf("            Le programme génère automatiquement une combinaison secrète.\n");
            printf("            L'étudiant propose une combinaison de 4 chiffres.\n");
            printf("            Le système renvoie deux informations :\n");
            printf("            - Le nombre de chiffres bien placés.\n");
            printf("            - Le nombre de chiffres corrects mais mal placés.\n");

            printf("            Votre mission :\n");
            printf("             Générer la séquence secrète.\n");
            printf("             Lire la proposition de l'utilisateur.\n");
            printf("             Comparer les deux séquences.\n");
            printf("             Calculer “bien placés” et “mal placés”.\n");
            printf("             Compter le nombre d'essais jusqu'à trouver la bonne combinaison.\n");

            printf("            But final :\n");
            printf("           Trouver la combinaison exacte\n");
            break;
        case 3:
            printf("========Defi Course de Robots===========\n");                           
            printf("            - Objectif : Trouver le chemin le plus court dans un labyrinthe\n");
            printf("            - Entrée : Une grille avec murs, départ et arrivée\n");
            printf("            - Sortie : La séquence de mouvements (N,S,E,O)\n");
            printf("            - Visualisation : Afficher le parcours solution \n");
            break;
        case 4:
            printf("===== Defi : Tri Ultime =====\n");
            printf("            Objectif :\n");
            printf("            Trier un tableau d'entiers selon une règle dynamique basée sur\n");
            printf("            un entier de comparaison.\n");
            printf("             Description :\n");
            printf("            Le tableau doit être trié en fonction de la somme de ses éléments\n");
            printf("            et de l'entier d.\n");
            printf("            Règles de tri :\n");
            printf("            • Si la somme des éléments > d → tri en ordre croissant\n");
            printf("            • Sinon → tri en ordre décroissant\n");
            printf("            Entrée :\n");
            printf("            n : taille du tableau\n");
            printf("            d : entier de comparaison\n");
            printf("            t : le tableau non trié d'entiers\n");
            printf("            Sortie :\n");
            printf("            Le tableau trié selon la règle ci-dessus\n");
            printf("            Le nombre total de comparaisons\n");
            printf("            Le nombre total de permutations\n");
            printf("            But :\n");
            printf("            Écrire un programme qui trie le tableau de manière efficace tout en\n"); 
            printf("            respectant la règle basée sur d et la somme des éléments\n");
            break;
        case 5:
            printf("=== Defi : Jeu Billard ===\n");

            printf("               Objectif :\n");
            printf("                Remplir un stock avec des boules numérotées et afficher le résultat final.\n");
            printf("                Description :\n");
            printf("                - Le joueur fait tomber des boules numérotées (1 à 8 dans des trous pour remplir le stock initialement vide.\n");
            printf("                - Le jeu se termine lorsque toutes les boules ont été insérées dans le stock.\n");
            printf("                - Une fois terminé le programme doit\n");
            printf("                   - Sortir toutes les boules du stock.\n");
            printf("                    - Afficher les numéros des boules dans l'ordre de sortie.\n");

            printf("                Entrées :\n");
            printf("                - Les numéros des boules tombées, un par ligne ou séparés par espace.\n");

            printf("                Sortie :\n");
            printf("               - La file (stock) rempli, affichée avec les numéros dans l'ordre de sortie.\n");break;           
        case 6:
            printf("=== Defi : Historique Dynamique de Messages ===\n");

            printf("                Objectif :\n");
            printf("                Gérer un historique de messages utilisant deux structures de données :\n");
            printf("                 -Une liste chaînée pour stocker les messages dans l'ordre.\n");
            printf("                 -Une pile (STACK) pour gérer la fonctionnalité UNDO.\n");

            printf("                Types de requêtes possibles :\n");
            printf("               ADD x\n");
            printf("                    Ajoute le message x à la fin de la liste chaînée.\n");
            printf("                    Ajoute également x au sommet de la pile.\n");
            printf("                UNDO\n");
            printf("                    Annule le dernier message ajouté.\n");
            printf("                   Le message est retiré de la pile et supprimé de la liste chaînée.\n");
            printf("                PRINT\n");
            printf("                    Affiche l'ensemble des messages encore présents dans la liste chaînée,\n");
            printf("                    dans leur ordre d'arrivée.\n");
            printf("                Votre mission :\n");
            printf("                 Implémenter une liste chaînée pour l'historique.\n");
            printf("                 Implémenter une pile pour les opérations UNDO.\n");
            printf("                 Exécuter les requêtes ADD, UNDO et PRINT.\n");
            printf("                 Assurer que UNDO supprime toujours le dernier message ajouté.\n");break;
        case 7:
            printf("=== Defi : Arbre Binaire de Recherche (BST) ===\n");

            printf("                Objectif :\n");
            printf("                Construire un arbre binaire de recherche (BST) à partir d'une série de nombres\n");
            printf("                et afficher certaines informations importantes sur cet arbre.\n");
            printf("                Description du défi :\n");
            printf("               L'utilisateur saisit une suite de nombres.\n");
            printf("                Le programme construit un BST selon les règles suivantes :\n");
            printf("                - Les valeurs plus petites vont dans le sous-arbre gauche.\n");
            printf("                - Les valeurs plus grandes dans le sous-arbre droit.\n");
            printf("               Travail demandé :\n");
            printf("                 Construire le BST à partir des valeurs saisies.\n");
            printf("                 Afficher le parcours In-Order (ce qui donne les valeurs triées).\n");
            printf("                 Calculer le nombre total de nœuds.\n");
            printf("                 Trouver la valeur minimum.\n");
            printf("                 Trouver la valeur maximum.\n");
            printf("                But final :\n");
            printf("                Comprendre et manipuler les arbres binaires de recherche\n");break;
        default:
            printf("aurevoir\n");break;                    
    }
    printf("====================\n");
}
int compare_files(const char *file1, const char *file2) {
    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");
    char ch1, ch2;

    if (fp1 == NULL || fp2 == NULL) {
        printf("erreur d'ouverture du fichier \n");
        if (fp1) fclose(fp1);
        if (fp2) fclose(fp2);
        return -1;
    }

    do {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);

        if (ch1 != ch2) {
            fclose(fp1);
            fclose(fp2);
            return -1; 
        }

    } while (ch1 != EOF && ch2 != EOF);

    fclose(fp1);
    fclose(fp2);

    if (ch1 == EOF && ch2 == EOF) {
        return 0;
    }
    else{
        return -1;

    } 
    
}



int main() {
    char username[64];
    int choix=0;
    printf("=== ARENA DE DEFIS ALGORITHMIQUES ===\n");
    printf("Entrez votre nom : ");
    scanf("%63s", username);
    getchar();

    do {
        printf("\nChoisissez un defi :\n");
        printf("1) Le Compte est Bon\n");
        printf("2) Mastermind Algorithmique \n");
        printf("3) Course de Robots\n");
        printf("4) Tri Ultime\n");
        printf("5) Jeu Billard\n");
        printf("6) Historique Dynamique de Messages\n");
        printf("7) Arbre Binaire de Recherche (BST)");
        printf("8) Quitter\n");
        printf("Votre choix : ");
        scanf("%d",&choix);
        if(choix==8) break;


        
        afficher_enonce(choix);
        char cmd_compile[256];
        char cmd_execute[512];
        char f_user[128], f_input[128], f_correct[128] ;
        char user_output_file[] = "user_output.txt"; 
        printf("Nom du fichier source utilisateur (ex: user.c) : ");
        //on a preparer des solutions pour le probleme par exemple pour le probleme 1 le fichier solution est user1.c
        scanf("%s", f_user); getchar();
        switch(choix) {
            case 1: strcpy(f_input, "input1.txt"); strcpy(f_correct, "correct1.txt"); break;
            case 2: strcpy(f_input, "input2.txt"); strcpy(f_correct, "correct2.txt"); break;
            case 3: strcpy(f_input, "input3.txt"); strcpy(f_correct, "correct3.txt"); break;
            case 4: strcpy(f_input, "input4.txt"); strcpy(f_correct, "correct4.txt"); break;
            case 5: strcpy(f_input, "input5.txt"); strcpy(f_correct, "correct5.txt"); break;
            case 6: strcpy(f_input, "input6.txt"); strcpy(f_correct, "correct6.txt"); break;
            case 7: strcpy(f_input, "input7.txt"); strcpy(f_correct, "correct7.txt"); break;
            case 8: continue;
            default: continue;

        }
            // 1️⃣ Compilation du code utilisateur
        sprintf(cmd_compile, "gcc %s -o user_program.exe", f_user);
        printf("Compilation du code utilisateur...\n");
        if(system(cmd_compile) != 0) {
            printf("Erreur de compilation\n");
        }
        else{
            printf("Compilation OK \n");

            // 2️⃣ Appel du juge correspondant
            sprintf(cmd_execute, ".\\user_program.exe < %s > %s", f_input, user_output_file);
            printf("Lancement du juge...\n");
            if (system(cmd_execute)!=0){
                printf("runtime error\n");
            }
            else {
                printf("exécution reussite\n");
                printf("verification des resultat...");
                int jugement = compare_files(user_output_file, f_correct);
                if (jugement==0){
                    printf("accepté\n");
                }
                else{
                    printf("resultat incorrect\n");
                }
            }
            
            
        }
    }while(choix>=1 && choix<=7);

    printf("Merci %s d'avoir utilisé Arena. Au revoir !\n", username);
    return 0;
}
