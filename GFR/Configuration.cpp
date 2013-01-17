#include "Configuration.h"
#include <string>

using namespace framework;

static ALLEGRO_CONFIG* m_ConfigFile;
const static char* CONFIG_PATH = "assets/Config/";
const static char* m_FullPath;

Configuration::Configuration()
{

}

Configuration::~Configuration()
{
	al_destroy_config(m_ConfigFile);
	delete CONFIG_PATH;
	delete m_FullPath;
}

bool Configuration::LoadConfigFile(const char* filename)
{
	std::string path = std::string(CONFIG_PATH);
	path += filename;

	m_FullPath = path.c_str();
	m_ConfigFile = al_load_config_file(m_FullPath);

	return m_ConfigFile != NULL;
}

const char* Configuration::GetStringValue(const char* section, const char* key)
{
	return al_get_config_value(m_ConfigFile, section, key);
}

const bool Configuration::GetBoolValue(const char* section, const char* key)
{
	const char* value = GetStringValue(section, key);
	std::string stringVal = std::string(value);

	return !stringVal.empty () && (std::strcmp(value, "true") == 0 || atoi(value) != 0);
}

const f32 Configuration::GetFloatValue(const char* section, const char* key)
{
	return atof(GetStringValue(section, key));
}

const u32 Configuration::GetIntValue(const char* section, const char* key)
{
	return atoi(GetStringValue(section, key));
}

void Configuration::SetValue(const char* section, const char* key, const char* value)
{
	al_set_config_value(m_ConfigFile, section, key, value);
}

void Configuration::SaveNewValues()
{
	ALLEGRO_CONFIG* newConfig = al_create_config();
	al_merge_config_into(newConfig, m_ConfigFile);

	al_destroy_config(m_ConfigFile);
	al_save_config_file(m_FullPath, newConfig);
	m_ConfigFile = newConfig;
}

void Configuration::ResetConfigFile(const char* filename)
{
	ALLEGRO_DISPLAY_MODE dispData;
	al_get_display_mode(al_get_num_display_modes()-1, &dispData);
	u32 resWidth = dispData.width;
	u32 resHeight = dispData.height;

	m_ConfigFile = al_create_config();

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

	std::string path = std::string(CONFIG_PATH);
	path += filename;
	al_save_config_file(path.c_str(), m_ConfigFile);
}