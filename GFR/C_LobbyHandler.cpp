#include "C_LobbyHandler.h"
#include "NetworkEnums.h"

using namespace game;
using namespace gfrNetworking;

CLobbyHandler::CLobbyHandler()
{
}

CLobbyHandler::~CLobbyHandler()
{

}

void CLobbyHandler::RegisterPacketTypes()
{
	RegisterPacketType(networking::PacketTypes::CHARACTER_SELECT, std::bind(&CLobbyHandler::ReceiveCharacterSelection, this, _1, _2));
}

void CLobbyHandler::Test(void* point)
{
	std::bind(&point, this, _1, _2);
}

void CLobbyHandler::SendCharacterSelection(networking::CharacterType character)
{
	ENetPacket* packet = m_Net->CreatePacket(networking::PacketTypes::CHARACTER_SELECT, true);
	WriteChar(packet, static_cast<char>(character));
	SendPacket(packet);
}

void CLobbyHandler::ReceiveCharacterSelection(ENetPacket* packet, ENetPeer* sender)
{

}