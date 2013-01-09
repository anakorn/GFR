#include "GFR_AL.h"

// begin temp
#include "InputMgr.h"

#include "ComponentBase.h"
#include "DrawComponent.h"
#include "PhysicsComponent.h"

#include "Entity.h"
#include "SystemBase.h"
#include "MovementSystem.h"

// end temp

int main(int argc, char** argv)
{
	if (!framework::GFR_AL::Create()) {
		return -1;
	}
	int drawCount = 0, updateCount = 0;
	bool redraw = false;
	while (1) {

		// GAME LOOP //
		ALLEGRO_EVENT ev;
		al_wait_for_event(framework::GFR_AL::s_EventQueue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) 
		{
			if (ev.any.source == al_get_timer_event_source(framework::GFR_AL::s_UpdateTimer)) {
				updateCount++;
			}
			else if (ev.any.source == al_get_timer_event_source(framework::GFR_AL::s_DrawTimer)) {
				redraw = true;
				drawCount++;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(framework::GFR_AL::s_EventQueue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_flip_display();
		}
	}

	framework::GFR_AL::Destroy();
	return 0;
}
		/********************* BEGIN TEMPORARY CODE *********************/
	
		/*framework::System* sys = new framework::MovementSystem();

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
			}
		}*/
	
		/********************* END TEMPORARY CODE **********************/