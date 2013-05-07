#include "GFRAL_ContentMgr.h"

using namespace framework;

void GFRAL_ContentMgr::SetDefaultDirectory()
{
	ALLEGRO_PATH* path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "assets");
	al_change_directory(al_path_cstr(path, '/'));

	al_destroy_path(path);
};

const std::string GFRAL_ContentMgr::GetContentDirectory(const char* subFolder)
{
	ALLEGRO_PATH* path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "assets");
	al_append_path_component(path, subFolder);

	std::string pathFileName_str = std::string(al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP));
	al_destroy_path(path);

	return pathFileName_str;
};

ALLEGRO_BITMAP* GFRAL_ContentMgr::CreateBitmap(const char* pathFile)
{
	return al_load_bitmap(pathFile);
};

void GFRAL_ContentMgr::DestroyBitmap(ALLEGRO_BITMAP* bitmap)
{
	al_destroy_bitmap(bitmap);
};

ALLEGRO_SAMPLE* GFRAL_ContentMgr::CreateSample(const char* pathFile)
{
	return al_load_sample(pathFile);
};

void GFRAL_ContentMgr::DestroySample(ALLEGRO_SAMPLE* sample)
{
	al_destroy_sample(sample);
};