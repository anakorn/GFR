#include "NetworkingSuite.h"
#include "../GFR/NetClient.h"

using namespace Testing;

NetworkingSuite::NetworkingSuite()
{
	TEST_ADD(NetworkingSuite::TestClientConnect);
	TEST_ADD(NetworkingSuite::TestPacketIO);
}

NetworkingSuite::~NetworkingSuite()
{

}

void NetworkingSuite::setup()
{

}

void NetworkingSuite::tear_down()
{

}

void NetworkingSuite::TestClientConnect()
{
	networking::NetClient client = networking::NetClient(11111);
}

void NetworkingSuite::TestPacketIO()
{

}