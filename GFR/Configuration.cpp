#include "Configuration.h"

using namespace framework;

static ALLEGRO_CONFIG* m_ConfigFile;
const static char* CONFIG_PATH = "assets/Config/";

Configuration::Configuration()
{

}

Configuration::~Configuration()
{
	al_destroy_config(m_ConfigFile);
}

void Configuration::LoadConfigFile(const char* filename)
{
	m_ConfigFile = al_load_config_file(filename);
}

const char* Configuration::GetValue(const char* section, const char* key)
{
	return al_get_config_value(m_ConfigFile, section, key);
}

void Configuration::SetValue(const char* section, const char* key, const char* value)
{
	al_set_config_value(m_ConfigFile, section, key, value);
}

void Configuration::ResetConfigFile()
{
	
}