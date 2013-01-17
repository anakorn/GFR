// TestManager
// Run all testing suites here
// to ensure all systems are functional

#include "NetworkingSuite.h"
#include <cpptest/cpptest-textoutput.h>

using namespace std;
using namespace UnitTesting;

Test::Suite testCollection;

// Add all test suites to the testCollection object here
void AddTests()
{
	testCollection.add(auto_ptr<NetworkingSuite>(new NetworkingSuite));
}

void RunTests()
{
	Test::TextOutput output(Test::TextOutput::Verbose);
	testCollection.run(output);
}

int main(int argc, char** argv)
{
	AddTests();
	RunTests();

	cout << "Press any key to exit.";
	system("pause");
	return 0;
}