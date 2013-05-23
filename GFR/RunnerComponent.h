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
			void Initialize(const std::string &name, const f32 &maxHealth, const f32 &movementSpeed, const f32 &jumpSpeed);

			f32 GetMaxHealth();
			f32 GetCurrentHealth();

			f32 GetBaseMovementSpeed();
			f32 GetCurrentMovementSpeed();

			f32 GetBaseJumpSpeed();
			f32 GetCurrentJumpSpeed();

			virtual const u64 GetMask() const { return MASK_RUNNER; }

		protected:
			f32 m_MaxHealth;
			f32 m_CurrentHealth;

			f32 m_BaseMovementSpeed;
			f32 m_CurrentMovementSpeed;

			f32 m_BaseJumpSpeed;
			f32 m_CurrentJumpSpeed;
		};

		COMPONENT_REGISTER(RunnerComponent, "RunnerComponent")
	};
};

#endif