#include <stdio.h>
#include <allegro5/allegro.h>

#include "Subsystem.h"
#include "Component.h"
#include "Entity.h"
#include <vector>

int main(int argc, char** argv)
{
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

	al_set_window_title(display, "Godfighter");
	
	/* Begin game loop */
	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();

	/********************* BEGIN TEMPORARY CODE *********************/
	
	u32 id = 0;
	std::vector<Framework::Entity> ents;

	while (true) {

		

	}
	
	/********************* END TEMPORARY CODE **********************/

	al_rest(5.0);
	
	/* End game loop */
	al_destroy_display(display);
	return 0;
}