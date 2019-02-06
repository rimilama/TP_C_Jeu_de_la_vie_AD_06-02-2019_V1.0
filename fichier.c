#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

void ecrire(int compt_vie, int compt_mort){
    FILE* fichier = NULL;
    fichier = fopen("Jeu_de_la_vie.txt", "w");
    fprintf(fichier, "Nombre de cellules vivantes : %d\nNombre de cellules mortes : %d\n", compt_vie, compt_mort);
    fclose(fichier);
}

void sauvegarde(int nJeu[][TAILLE]){
    int nI,nJ;
    FILE* fichier = NULL;
    fichier = fopen("Jeu_de_la_vie.txt", "a");
    fprintf(fichier, "\nSauvegarde de la derniere partie (Ne surtout pas modifier):\n\n");
    for(nI=1;nI<TAILLE-1;nI++){
        for(nJ=1;nJ<TAILLE-1;nJ++){
            if(nJeu[nI][nJ]==1){
                fprintf(fichier, "1");
            }else{
                fprintf(fichier, "0");
            }
        }
    }
    fclose(fichier);
}

int charger(int nJeu[][TAILLE]){
    int nI,nJ,compt=0,nCarac;
    FILE* fichier = fopen("Jeu_de_la_vie.txt", "r");
    if(fichier!=NULL){
        do{
            nCarac = fgetc(fichier);
            if(nCarac=='\n'){
                compt++;
            }
            if(feof(fichier)!=0){
                printf("\nAucune partie n'est sauvegarder !\nNouvelle partie demaree !\n");
                fclose(fichier);
                fflush(stdin);
                getchar();
                return 0;
            }
        }while(compt<5);
        for(nI=0;nI<TAILLE;nI++){
            for(nJ=0;nJ<TAILLE;nJ++){
                if(nI==0 || nI==TAILLE-1 || nJ==0 || nJ==TAILLE-1){
                    nJeu[nI][nJ] = 0;
                }else{
                    nCarac = getc(fichier);
                    if((int)nCarac==48){
                        nJeu[nI][nJ] = 0;
                    }else{
                        nJeu[nI][nJ] = 1;
                    }
                }
            }
        }
    }else{
        printf("\nAucun fichier n'existe !\nNouvelle partie demaree !\n");
        fflush(stdin);
        getchar();
        return 0;
    }
    fclose(fichier);
    return 1;
}
