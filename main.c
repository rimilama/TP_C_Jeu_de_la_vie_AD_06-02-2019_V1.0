#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    int nJeu[TAILLE][TAILLE];
    demarage(nJeu);
    boucle_de_jeu(nJeu);
    return 0;
}


void boucle_de_jeu(int nJeu[][TAILLE]){
    char cChoix;
    do{
        system("cls");
        afficher(nJeu);
        cChoix = menu();
        if(cChoix=='1'){
            mise_a_jour(nJeu);
        }
    }while(cChoix!='2' && cChoix!='3');
    if(cChoix=='2'){
        sauvegarde(nJeu);
    }
}
