#pragma once 
#ifndef GFR_FRAMEWORK_ALLEGRO_CONFIGURATION_H
#define GFR_FRAMEWORK_ALLEGRO_CONFIGURATION_H

#include "Common.h"
#include <allegro5/allegro5.h>
#include <string>

namespace framework
{
	class Configuration
	{
	public:
		Configuration();
		~Configuration();

		static bool		LoadConfigFile(const std::string filename);

		static const	std::string GetStringValue(const std::string section, const std::string key);
		static const	bool GetBoolValue(const std::string section, const std::string key);
		static const	f32 GetFloatValue(const std::string section, const std::string key);
		static const	u32 GetIntValue(const std::string section, const std::string key);

		static void		SetValue(const std::string section, const std::string key, const std::string value);
		static void		SaveNewValues();

		// Programmatically set all default values
		static void		ResetConfigFile(const std::string filename);

	private:
		static ALLEGRO_CONFIG*		s_ConfigFile;
		static const std::string	s_ConfigPath;
		static std::string			s_FullPath;

	};
};

#endif