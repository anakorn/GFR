#ifndef GFR_GAME_COMPONENTS_CHARACTERS_RUNNERCOMPONENT_H
#define GFR_GAME_COMPONENTS_CHARACTERS_RUNNERCOMPONENT_H

#include "Common.h"
#include "PlayableCharacter.h"

namespace game
{
	namespace characters
	{
		class RunnerComponent : public PlayableCharacter
		{
		public:
			void Initialize(const std::string &name, const f32 &maxHealth);

			f32 GetMaxHealth();
			f32 GetCurrentHealth();

			virtual const u64 GetMask() const { return MASK_RUNNER; }

		protected:
			f32 m_MaxHealth;
			f32 m_CurrentHealth;
		};

		COMPONENT_REGISTER(RunnerComponent, "RunnerComponent")
	};
};

#endif