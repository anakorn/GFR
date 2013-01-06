#pragma once
#ifndef NETWORKINGSUITE_H
#define NETWORKINGSUITE_H

#include "cpptest/cpptest-suite.h"

namespace Testing
{
	class NetworkingSuite : public Test::Suite
	{
	public:
		NetworkingSuite();
		~NetworkingSuite();

	protected:
		virtual void setup() override;
		virtual void tear_down() override;
	};
};

#endif