#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "init.h"



void demarage(int nJeu[][TAILLE]){
    int chargement;
    char cChoix;
    printf("Que voulez vous faire ?\n\n");
    printf("1 - Nouvelle partie\n");
    printf("2 - Charger la derniere partie (si elle existe)\n");
    fflush(stdin);
    cChoix = getchar();
    while(cChoix!='1' && cChoix!='2'){
        printf("\nERREUR\n");
        fflush(stdin);
        cChoix = getchar();
    }
    if(cChoix=='1'){
        init(nJeu);
    }else{
        chargement = charger(nJeu);
        if(chargement==0){
            init(nJeu);
        }
    }
}

void init(int nJeu[][TAILLE]){
    int nI,nJ;
	srand(time(NULL));
    for(nI=0;nI<TAILLE;nI++){
        for(nJ=0;nJ<TAILLE;nJ++){
            if(nI==0 || nI==TAILLE-1 || nJ==0 || nJ==TAILLE-1){
                nJeu[nI][nJ] = 0;
            }else{
                nJeu[nI][nJ] = rand()%2;
            }
        }
    }
}
