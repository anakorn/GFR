#include "..\GFR\NetClient.h"
#include "NetworkingSuite.h"

using namespace UnitTesting;

NetworkingSuite::NetworkingSuite()
{
	TEST_ADD(NetworkingSuite::TestClientConnect);
	TEST_ADD(NetworkingSuite::TestPacketIO);
}

NetworkingSuite::~NetworkingSuite()
{

}

void NetworkingSuite::TestClientConnect()
{

}

void NetworkingSuite::TestPacketIO()
{
	networking::NetClient client = networking::NetClient(11111);
}