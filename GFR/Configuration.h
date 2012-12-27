#pragma once 
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "allegro5/allegro5.h"

namespace framework
{
	class Configuration
	{
	public:
		Configuration();
		~Configuration();

		static void LoadConfigFile(const char* filename);

		static const char* GetValue(const char* section, const char* key);
		static void SetValue(const char* section, const char* key, const char* value);

		// Programmatically set all default values
		static void ResetConfigFile();
	};
};

#endif