#include <stdio.h>
#include <allegro5/allegro.h>
 
int main(int argc, char** argv) {
	
	ALLEGRO_DISPLAY* display = NULL;

	/* Systems Initialization */
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	
	display = al_create_display(640, 480);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}
	
	/* Begin game loop */
	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();
	
	while (true) {

	}

	al_rest(5.0);
	
	/* End game loop */
	al_destroy_display(display);
	return 0;
}