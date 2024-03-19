#include <stdio.h>
#include <stdlib.h>
#include "drawing.h"


#define COURBE_NIVEAU 4


#define LARGEUR 1200
#define HAUTEUR 1200
#define TAILLE_SEGMENT_INIT 400


int chemin[65536]={0};
int etape=0;
int longueur_segment = TAILLE_SEGMENT_INIT;

int nbVirages();
void ajoutePlis();
void init_dragon();

int main() {
    int i=0;
    
    init_dragon();
	
    turn(90,RIGHT);
    draw(longueur_segment);

    repeat (10) {

    } loop;
    
    display_drawing();

    return 0;
}

int nbVirages() {
    /*
    etape  chemin                       - nombre de virages
           debut    milieu fin            debut milieu fin
    1               G                   - 0     1      0   =   1 + 2 x 0  =  1  virage
    2      G        G      D            - 1     1      1   =   1 + 2 x 1  =  3  virages
    3      GGD      G      GDD          - 3     1      3   =   1 + 2 x 3  =  7  virages
    4      GGDGGDD  G      GGDDGDD      - 7     1      7   =   1 + 2 x 7  =  15 virages
    ...
    x-1                                                                   =  p  virages
    x                                                      =   1 + 2 x p        virages
    ...
    */

    int p=0;

    repeat (etape) {
        p = 1 + 2 * p;
    } loop;

    return p;
}

void ajoutePlis() {
    int nouveauMilieu = nbVirages();
    int i=1;

    G(chemin, nouveauMilieu);

    repeat(nouveauMilieu) {
        if ( G_OU_D(chemin, nouveauMilieu - i) == DROITE ) {
            G(chemin, nouveauMilieu + i);
        } else {
            D(chemin, nouveauMilieu + i);
        }
        i++;
    } loop;

    etape = etape + 1;
    return;
}

void init_dragon() {
    repeat (COURBE_NIVEAU) {
        ajoutePlis();
        longueur_segment = (longueur_segment * (7 + (0.027 * COURBE_NIVEAU))) / 10;        
    } loop;

    init_drawing(LARGEUR,HAUTEUR);
    return;
}
