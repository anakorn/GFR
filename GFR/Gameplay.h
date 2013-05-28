#ifndef GFR_GAME_GAMESTATE_STATES_GAMEPLAY_H
#define GFR_GAME_GAMESTATE_STATES_GAMEPLAY_H

#include "State.h"
#include "PlayableCharacter.h"
#include "PhysicsMgr.h"
#include "Entity.h"
#include "MovementSystem.h"
#include "RunnerControlSystem.h"
#include "RenderSystem.h"
#include "Camera.h"
#include "Vec2.h"

namespace game
{
	namespace gameState
	{
		class Gameplay : public State, public agui::ActionListener, public b2Draw
		{
		public:
			Gameplay(characters::Class playerCharacter);
			~Gameplay();

			virtual void Update() override;
			virtual void Render() override;
			virtual void actionPerformed(const agui::ActionEvent &evt) override;

			// TODO: Replace with more appropriate way for creating entities
			void CreateTestPlayer(Vec2f pos);
			void CreateTestBox(Vec2f pos);
			void CreateTestBoundary(Vec2f startPos, Vec2f endPos);

			/* Box2D debug drawing functions */
			virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
			virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
			virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
			virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
			virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
			virtual void DrawTransform(const b2Transform& xf);

		private:
			framework::RunnerControlSystem	m_ControlSystem;
			framework::MovementSystem		m_MovementSystem;
			framework::RenderSystem			m_RenderSystem;
			framework::PhysicsMgr			m_PhysMgr;
			std::list <framework::Entity>	m_Entities;
			framework::Camera				m_Camera;
		};
	};
};

#endif