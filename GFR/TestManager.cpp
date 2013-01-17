// TestManager
// Run all testing suites here
// to ensure all systems are functional

#include <cpptest/cpptest-suite.h>
#include <cpptest/cpptest-textoutput.h>
#include <cpptest/cpptest-htmloutput.h>
#include "TestManager.h"
#include "NetworkingSuite.h"

using namespace UnitTesting;
using namespace std;

Test::Suite testCollection;

// Add all test suites to the testCollection object here
void TestManager::AddTests()
{
	testCollection.add(auto_ptr<NetworkingSuite>(new NetworkingSuite));
}

bool TestManager::RunTests()
{
	Test::TextOutput output(Test::TextOutput::Verbose);
	return testCollection.run(output);
}

bool TestManager::Execute()
{
	AddTests();
	return RunTests();
}