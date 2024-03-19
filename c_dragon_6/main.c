#include <stdio.h>
#include <stdlib.h>
#include "drawing.h"

#define LARGEUR 1200
#define HAUTEUR 1200

int main() {
	init_drawing(LARGEUR,HAUTEUR);

	

    display_drawing();

    return 0;
}