#include "GFRAL_Content.h"

using namespace framework;

void GFRAL_Content::SetDefaultDirectory()
{
	ALLEGRO_PATH* path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "assets");
	al_change_directory(al_path_cstr(path, '/'));

	al_destroy_path(path);
};

const std::string GFRAL_Content::GetContentDirectory(const char* subFolder)
{
	ALLEGRO_PATH* path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "assets");
	al_append_path_component(path, subFolder);

	std::string pathFileName_str = std::string(al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP));
	al_destroy_path(path);

	return pathFileName_str;
};

ALLEGRO_BITMAP* GFRAL_Content::CreateBitmap(const char* pathFile)
{
	return al_load_bitmap(pathFile);
};

void GFRAL_Content::DestroyBitmap(ALLEGRO_BITMAP* bitmap)
{
	al_destroy_bitmap(bitmap);
};

ALLEGRO_SAMPLE* GFRAL_Content::CreateSample(const char* pathFile)
{
	return al_load_sample(pathFile);
};

void GFRAL_Content::DestroySample(ALLEGRO_SAMPLE* sample)
{
	al_destroy_sample(sample);
};