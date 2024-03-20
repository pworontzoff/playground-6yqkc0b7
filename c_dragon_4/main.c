#include <stdio.h>
#include <stdlib.h>
#include "drawing.h"

#define LARGEUR 740
#define HAUTEUR 400

int main() {
	init_drawing(LARGEUR,HAUTEUR);

    draw(100);

	turn(90,RIGHT);
	
	draw(100);
	
	turn(90,LEFT);
	
	draw(100);

	turn(90,RIGHT);

	draw(100);
	
    display_drawing();

    return 0;
}
