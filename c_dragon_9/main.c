#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "drawing.h"


#define COURBE_NIVEAU 15


#define LARGEUR 1200
#define HAUTEUR 1200
#define TAILLE_SEGMENT_INIT 400


int chemin[65536]={0};
int etape=0;
int longueur_segment = TAILLE_SEGMENT_INIT;

void ajoutePlis();
void init_dragon();

int main() {
    int i=0;
    
    init_dragon();
    init_drawing(LARGEUR,HAUTEUR);

    turn(90,RIGHT);
    draw(longueur_segment);

    repeat (10) {
        if (G_OU_D(chemin, i) == DROITE) {
           turn(90,RIGHT);
        } else {
           turn(90,LEFT);
        }
        draw(longueur_segment);
        i = i + 1;
    } loop;
    
    display_drawing();

    return 0;
}

void ajoutePlis() {
    int nouveauMilieu = pow(2,etape)-1;
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

    return;
}
