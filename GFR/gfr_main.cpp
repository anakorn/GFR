#include "GFR_AL.h"

#include "InputMgr.h"
#include "SystemBase.h"
#include "MovementSystem.h"
#include "Entity.h"
#include "ComponentBase.h"
#include "PhysicsComponent.h"
#include <vector>

int main(int argc, char** argv)
{
	if (!framework::GFR_AL::Create()) {
		return -1;
	}

	framework::GFR_AL::RunGameLoop();

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