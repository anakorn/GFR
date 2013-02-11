#ifndef GFR_GAME_NETWORKING_CONNECTIONSHANDLER_H
#define GFR_GAME_NETWORKING_CONNECTIONSHANDLER_H

#include "PacketHandler.h"

namespace game
{
	namespace gfrNetworking
	{
		class ConnectionsHandler : public PacketHandler
		{
		public:
			ConnectionsHandler();
			~ConnectionsHandler();
		protected:
			virtual void HandlePacket(const ENetPacket &packet) override;
		private:
			NetworkPlayer* m_PlayerList[4];
			std::vector<ENetPeer> m_UnseatedPlayers;
		};
	};
};

#endif