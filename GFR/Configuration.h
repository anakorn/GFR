#pragma once 
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "Common.h"
#include <allegro5/allegro5.h>

namespace framework
{
	class Configuration
	{
	public:
		Configuration();
		~Configuration();

		static bool LoadConfigFile(const char* filename);

		static const char* GetStringValue(const char* section, const char* key);
		static const bool GetBoolValue(const char* section, const char* key);
		static const f32 GetFloatValue(const char* section, const char* key);
		static const u32 GetIntValue(const char* section, const char* key);

		static void SetValue(const char* section, const char* key, const char* value);
		static void SaveNewValues();

		// Programmatically set all default values
		static void ResetConfigFile(const char* filename);
	};
};

#endif