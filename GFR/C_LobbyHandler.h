#ifndef GFR_GAME_NETWORKING_CLOBBYHANDLER_H
#define GFR_GAME_NETWORKING_CLOBBYHANDLER_H

#include "PacketHandler.h"
#include "Connection.h"

namespace game
{
	namespace gfrNetworking
	{
		class CLobbyHandler : public networking::PacketHandler
		{
		public:
			CLobbyHandler();
			~CLobbyHandler();

			void SendCharacterSelection(networking::CharacterType character);
		protected:
			void RegisterPacketTypes() override;
		private:
			void ReceiveCharacterSelection(ENetPacket* packet, ENetPeer* sender);
			void Test(void* point);
		};
	};
};

#endif