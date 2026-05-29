#include<stdio.h>

void tri_tab(int t[], int n, int d){
    int i, aux, j, test, s=0;
    int *p = t;

    // somme des valeurs du tableau
    for(i=0;i<n;i++){
        s += p[i];
    }

    if(s >= d){
        // tri par ordre croissant
        do{
            test = 0;
            for(j=0;j<n-1;j++){
                if(p[j] > p[j+1]){
                    aux = p[j];
                    p[j] = p[j+1];
                    p[j+1] = aux;
                    test = 1;
                }
            }
        }while(test==1);
    }
    else{
        // tri par ordre décroissant
        do{
            test = 0;
            for(j=0;j<n-1;j++){
                if(p[j] < p[j+1]){
                    aux = p[j];
                    p[j] = p[j+1];
                    p[j+1] = aux;
                    test = 1;
                }
            }
        }while(test==1);
    }
}

int main(){
    int n, i, d;
    scanf("%d",&d);
    scanf("%d",&n);

    int t[n];

    // remplissage du tableau
    for(i=0;i<n;i++){
        scanf("%d",&t[i]);
    }

    // tri
    tri_tab(t,n,d);

    // affichage du tableau trié
    for(i=0;i<n;i++){
        printf("%d ", t[i]);
    }
    printf("\n");

    return 0;
}