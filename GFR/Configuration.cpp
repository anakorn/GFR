#include "Configuration.h"
#include <string>

using namespace framework;

static ALLEGRO_CONFIG* m_ConfigFile;
const static char* CONFIG_PATH = "assets/Config/";

Configuration::Configuration()
{

}

Configuration::~Configuration()
{
	al_destroy_config(m_ConfigFile);
	delete CONFIG_PATH;
}

bool Configuration::LoadConfigFile(const char* filename)
{
	std::string path = std::string(CONFIG_PATH);
	path += filename;
	m_ConfigFile = al_load_config_file(path.c_str());

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

void Configuration::ResetConfigFile(const char* filename)
{
	ALLEGRO_DISPLAY_MODE dispData;
	al_get_display_mode(al_get_num_display_modes()-1, &dispData);
	u32 resWidth = dispData.width;
	u32 resHeight = dispData.height;

	m_ConfigFile = al_create_config();

	// SCREEN VALUES
	// fullscreen: true
	// width, height: current screen resolution
	al_add_config_section(m_ConfigFile, "SCREEN");

	SetValue("SCREEN", "fullscreen", "true");
	std::string width = std::to_string(resWidth);
	SetValue("SCREEN", "width", width.c_str());
	std::string height = std::to_string(resHeight);
	SetValue("SCREEN", "height", height.c_str());

	std::string path = std::string(CONFIG_PATH);
	path += filename;
	al_save_config_file(path.c_str(), m_ConfigFile);
}