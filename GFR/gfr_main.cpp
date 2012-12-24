#include <stdio.h>
#include <allegro5/allegro.h>

#include "SystemBase.h"
#include "MovementSystem.h"
#include "Entity.h"
#include "ComponentBase.h"
#include "ComponentDerived.h"
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
	
	framework::System* sys = new framework::MovementSystem();

	std::vector<framework::Entity> ents;
	framework::Entity ent = framework::Entity();
	ent.AttachComponent("PhysicsComponent");
	ent.AttachComponent("DrawComponent");
	ents.push_back(ent);

	while (true) {
		for (auto it = ents.begin(); it != ents.end(); ++it) {
			framework::Entity& currEnt = *it;
			if (sys->IsEntityCompatible(currEnt)) {
				sys->ProcessEntity(currEnt);
			}
			
			fprintf(stdout, "%f.00\n", ((framework::PhysicsComponent*)ent.GetComponent("PhysicsComponent"))->x);
		}
	}
	
	/********************* END TEMPORARY CODE **********************/

	al_rest(5.0);
	
	/* End game loop */
	al_destroy_display(display);
	return 0;
}