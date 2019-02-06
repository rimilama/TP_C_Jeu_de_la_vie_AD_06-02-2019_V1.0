#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"

void afficher(int nJeu[][TAILLE]){
    int nI,nJ, compt_vie=0, compt_mort=0;
    for(nI=1;nI<TAILLE-1;nI++){
        for(nJ=1;nJ<TAILLE-1;nJ++){
            if(nJeu[nI][nJ]==1){
                printf("|O|");
                compt_vie++;
            }else{
                printf("| |");
                compt_mort++;
            }
        }
        printf("\n");
    }
    printf("\nNombre de cellules vivantes : %d\nNombre de cellules mortes : %d\n", compt_vie, compt_mort);
    ecrire(compt_vie, compt_mort);
}

char menu(){
    char cChoix;
    printf("\n1 - Cycle suivant\n");
    printf("2 - Sauvegarder et quitter\n");
    printf("3 - Quitter\n");
    fflush(stdin);
    cChoix = getchar();
    while(cChoix!='1' && cChoix!='2' && cChoix!='3'){
        printf("\nERREUR\n");
        fflush(stdin);
        cChoix = getchar();
    }
    system("cls");
    return cChoix;
}
