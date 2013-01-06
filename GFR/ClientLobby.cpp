#include "ClientLobby.h"

using namespace gamestate;

ClientLobby::ClientLobby(const char* ip, const u32 &port)
	: GameState(StateTypes::CLIENT_LOBBY)
{

}

ClientLobby::~ClientLobby()
{

};