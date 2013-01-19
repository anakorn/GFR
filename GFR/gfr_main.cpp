#include "GFR_AL.h"

/*
   ______            __ ______ _         __     __             
  / ____/____   ____/ // ____/(_)____ _ / /_   / /_ ___   _____
 / / __ / __ \ / __  // /_   / // __ `// __ \ / __// _ \ / ___/
/ /_/ // /_/ // /_/ // __/  / // /_/ // / / // /_ /  __// /    
\____/ \____/ \__,_//_/    /_/ \__, //_/ /_/ \__/ \___//_/     
							  /____/                           
*/

int main(int argc, char** argv)
{
	// Set up Allegro systems
	if (!framework::GFR_AL::InitSystems()) {
		return -1;
	}

	// Set up game-specific systems
	framework::GFR_AL::InitGame(game::stateTypes::MAIN_MENU);

	// Main game loop
	framework::GFR_AL::RunGameLoop();

	// Cleanup
	framework::GFR_AL::DestroySystems();

	return 0;
}
