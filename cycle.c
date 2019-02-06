#include <stdio.h>
#include <stdlib.h>
#include "cycle.h"


void mise_a_jour(int nJeu[][TAILLE]){
    int nI,nJ,compt, nTemp_Jeu[TAILLE][TAILLE];
    for(nI=1;nI<TAILLE-1;nI++){
        for(nJ=1;nJ<TAILLE-1;nJ++){
            compt=0;
            compt = nJeu[nI-1][nJ-1]+nJeu[nI-1][nJ]+nJeu[nI-1][nJ+1]+nJeu[nI][nJ-1]+nJeu[nI][nJ+1]+nJeu[nI+1][nJ-1]+nJeu[nI+1][nJ]+nJeu[nI+1][nJ+1];
            if(nJeu[nI][nJ]==1 && (compt<2 || compt>3)){
                nTemp_Jeu[nI][nJ]=0;
            }else if(nJeu[nI][nJ]==0 && compt==3){
                nTemp_Jeu[nI][nJ]=1;
            }else if(nJeu[nI][nJ]==1){
                nTemp_Jeu[nI][nJ]=1;
            }else if(nJeu[nI][nJ]==0){
                nTemp_Jeu[nI][nJ]=0;
            }
        }
    }

    for(nI=1;nI<TAILLE-1;nI++){
        for(nJ=1;nJ<TAILLE-1;nJ++){
            nJeu[nI][nJ]=nTemp_Jeu[nI][nJ];
        }
    }
}
