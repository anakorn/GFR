#include "ContentMgr.h"

namespace fs = boost::filesystem;

boost::unordered_map<std::string, Texture*>* ContentMgr::textureMap = new boost::unordered_map<std::string, Texture*>();
boost::unordered_map<std::string, Sound*>* ContentMgr::soundMap = new boost::unordered_map<std::string, Sound*>();

namespace
{
	// TODO: Figure out how to pass in different template maps as parameters.
	void LoadContentMap(const char* subFolder, boost::unordered_map<std::string, Texture*>* textureMap)
	{
		ALLEGRO_PATH* path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
		al_append_path_component(path, "..");
		al_append_path_component(path, "GFR");
		al_append_path_component(path, "Assets");
		al_append_path_component(path, subFolder);

		std::string start = al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP);

		fs::recursive_directory_iterator end;
		fs::recursive_directory_iterator rdi(start);

		while (rdi != end)
		{
			const std::string path = rdi->path().string();

			try
			{
				// TODO fix this line to be more flexible & cross-platform.
				const std::string key = path.substr(path.find_last_of("\\") + 1, path.length() - 1);
				textureMap->insert(std::pair<const std::string, Texture*>(key, new Texture(path.c_str())));
				
				++rdi;
			}
			catch(fs::filesystem_error)
			{
				rdi.no_push();
				++rdi;
			}
		}
	}
}

// Change working directory path to go straight
// to assets folder to minimize key length.
void ContentMgr::Initialize()
{
	ALLEGRO_PATH* path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	// TODO: Resources path defaults to debug folder with exe inside
	// of GFR. Figure out where our resources should go in deployment.
	al_append_path_component(path, "..");
	al_append_path_component(path, "GFR");
	al_append_path_component(path, "assets");

	al_change_directory(al_path_cstr(path, '/'));

	al_destroy_path(path);
};

// TODO: Change this to run with Boost::FileSystem
bool ContentMgr::LoadAllContent()
{
	LoadContentMap("Textures", textureMap);
	
	return true;
};

void ContentMgr::UnloadAllContent()
{
	textureMap->clear();
	soundMap->clear();
}

template<typename T>
T* ContentMgr::LoadContent(const std::string filePath)
{
	throw ContentLoadFailedException(filePath, "Content load failed. Non-existent content type! (ContentMgr::LoadContent)");
};

template<>
Texture* ContentMgr::LoadContent<Texture>(const std::string filePath)
{
	try
	{
		return textureMap->at(filePath);
	}
	catch(std::out_of_range)
	{
		return NULL;
		// TODO: Look for file here.
	}
};

template<>
Sound* ContentMgr::LoadContent<Sound>(const std::string filePath)
{
	return soundMap->at(filePath);
};

template<typename T>
void ContentMgr::UnloadContent(const std::string file)
{
	return ContentUnLoadFailedException(filePath, "Content unload failed. Non-existent content type! (ContentMgr::UnloadContent");
};

template<>
void ContentMgr::UnloadContent<Texture>(const std::string file)
{
	textureMap->erase(textureMap->find(file));
};

template<>
void ContentMgr::UnloadContent<Sound>(const std::string file)
{
	soundMap->erase(soundMap->find(file));
};