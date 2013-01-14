#pragma once
#ifndef TESTMANAGER_H
#define TESTMANAGER_H

namespace UnitTesting
{
	class TestManager
	{
	public:
		TestManager();
		~TestManager();

		// Runs all tests and returns true only if all pass
		bool Execute();
	private:
		void AddTests();
		bool RunTests();
	};
};

#endif