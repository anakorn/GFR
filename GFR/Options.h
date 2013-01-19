#pragma once
#ifndef OPTIONS_H
#define MAINMENU_H

#include "State.h"

namespace game
{
	namespace gameState
	{
		class Options : public State
		{
		public:
			Options();
			~Options();
		};
	};
};

#endif