#include "Configuration.h"

using namespace framework;

ALLEGRO_CONFIG*		Configuration::s_ConfigFile;
const std::string	Configuration::s_ConfigPath = "assets\\Config";
std::string			Configuration::s_FullPath;

Configuration::Configuration()
{

}

Configuration::~Configuration()
{
	al_destroy_config(s_ConfigFile);
}

bool Configuration::LoadConfigFile(const std::string filename)
{
	// Set up s_FullPath with "assets/Config/" directory
	ALLEGRO_PATH* allegroPath = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(allegroPath, s_ConfigPath.c_str());

	s_FullPath = std::string(al_path_cstr(allegroPath, ALLEGRO_NATIVE_PATH_SEP));
	s_FullPath.append(filename);
	al_destroy_path(allegroPath);

	s_ConfigFile = al_load_config_file(s_FullPath.c_str());
	return s_ConfigFile != NULL;
}

const std::string Configuration::GetStringValue(const std::string section, const std::string key)
{
	return al_get_config_value(s_ConfigFile, section.c_str(), key.c_str());
}

const bool Configuration::GetBoolValue(const std::string section, const std::string key)
{
	const std::string value = GetStringValue(section, key);
	return !value.empty() && (value.compare("1") == 0 || value.compare("true") == 0);
}

const f32 Configuration::GetFloatValue(const std::string section, const std::string key)
{
	return stof(GetStringValue(section, key));
}

const u32 Configuration::GetIntValue(const std::string section, const std::string key)
{
	return stoi(GetStringValue(section, key));
}

void Configuration::SetValue(const std::string section, const std::string key, const std::string value)
{
	al_set_config_value(s_ConfigFile, section.c_str(), key.c_str(), value.c_str());
}

void Configuration::SaveNewValues()
{
	ALLEGRO_CONFIG* newConfig = al_create_config();
	al_merge_config_into(newConfig, s_ConfigFile);

	al_destroy_config(s_ConfigFile);
	al_save_config_file(s_FullPath.c_str(), newConfig);
	s_ConfigFile = newConfig;
}

void Configuration::ResetConfigFile(const std::string filename)
{
	ALLEGRO_DISPLAY_MODE dispData;
	al_get_display_mode(al_get_num_display_modes()-1, &dispData);
	u32 resWidth = dispData.width;
	u32 resHeight = dispData.height;

	s_ConfigFile = al_create_config();

	// SCREEN VALUES
	// fullscreen: false(make true in release version)
	// width, height: current screen resolution
	SetValue("SCREEN", "fullscreen", "false");
	std::string width = std::to_string(resWidth);
	SetValue("SCREEN", "width", width.c_str());
	std::string height = std::to_string(resHeight);
	SetValue("SCREEN", "height", height.c_str());

	// SAVED FIELD VALUES
	// gameName: My Game
	// ip: 127.0.0.1
	// port: 24184
	SetValue("SAVEDFIELD", "gameName", "My Game");
	SetValue("SAVEDFIELD", "ip", "127.0.0.1");
	SetValue("SAVEDFIELD", "port", "24184");

	std::string path = std::string(s_ConfigPath);
	path += filename;
	al_save_config_file(path.c_str(), s_ConfigFile);
}