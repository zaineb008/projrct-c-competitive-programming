#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

int used [6];
char resultat[200];

bool expression(double res, char *form, int nb,int c,int T[]) {
    if (fabs(res - c) ==0 && nb == 6) {
        strcpy(resultat, form);
        return true;
    }

    for (int i = 0; i < 6; i++) {
        if (!used[i]) {
            used[i] = 1;
            char nov[200];

            if (nb == 0) { 
                sprintf(nov, "%.0f",(double) T[i]);
                if (expression(T[i], nov, 1,c,T)) {
                    return true;
                }
            } 
            else {
                sprintf(nov, "(%s+%d)", form, T[i]);
                if (expression(res + T[i], nov, nb + 1,c,T)){
                  return true;  
                } 

                sprintf(nov, "(%s-%d)", form, T[i]);
                if (expression(res - T[i], nov, nb + 1,c,T)){
                   return true ;
                } 

                sprintf(nov, "(%s*%d)", form, T[i]);
                if (expression(res*T[i], nov, nb + 1,c,T)){
                  return true;  
                } 

                if (T[i] != 0) {
                    sprintf(nov, "(%s/%d)", form, T[i]);
                    if (expression(res / T[i], nov, nb + 1,c,T)){
                        return true ;
                        
                    } 
                }
            }
            used[i] = 0;
        }
    }
    return false;
}

int main() {
    int cible;
    int T[6];
    for (int i = 0; i < 6; i++) {
        scanf("%d", &T[i]);
    }

    scanf("%d", &cible);
    
    char formule[200];
    if ((expression(0, formule, 0,cible,T))){
       
        char ch[200];
        sprintf(ch, "%s = %d", resultat, cible);
        printf("%s\n",ch);
        

    }
    else{
        printf( "erreur\n");
        

    }
    return 0;
   
}