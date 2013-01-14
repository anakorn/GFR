#pragma once
#ifndef NETWORKINGSUITE_H
#define NETWORKINGSUITE_H

#include <cpptest/cpptest-suite.h>

namespace UnitTesting
{
	class NetworkingSuite : public Test::Suite
	{
	public:
		NetworkingSuite();
		~NetworkingSuite();

	private:
		void TestClientConnect();
		void TestPacketIO();
	};
};

#endif