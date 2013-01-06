// Testing Main
// Run all testing suites here
// to ensure all systems are functional

#include "cpptest/cpptest-suite.h"
#include "cpptest/cpptest-textoutput.h"
#include "cpptest/cpptest-htmloutput.h"

#include "NetworkingSuite.h"

using namespace Testing;
using namespace std;

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

	cout << "Press any key to exit. \n\n";
	system("PAUSE");

	return 0;
}