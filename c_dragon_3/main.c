#include <stdio.h>
#include <stdlib.h>
#include "drawing.h"

#define LARGEUR 1200
#define HAUTEUR 1200

int main() {
	init_drawing(LARGEUR,HAUTEUR);

    draw(100);

	turn(90,RIGHT);
	
	draw(100);

	
	
    display_drawing();

    return 0;
}