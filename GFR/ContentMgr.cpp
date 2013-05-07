#include "ContentMgr.h"
#include "GFRAL_ContentMgr.h"
#include "ContentLoadException.h"
#include "ContentUnloadException.h"
#include "GFR_AL.h"

namespace fs = boost::filesystem;
using namespace framework;

boost::unordered_map<std::string, Texture*>* ContentMgr::textureMap = new boost::unordered_map<std::string, Texture*>();
boost::unordered_map<std::string, Sound*>* ContentMgr::soundMap = new boost::unordered_map<std::string, Sound*>();

// Change working directory path to go straight
// to assets folder to minimize key length.
void ContentMgr::Initialize()
{
	GFRAL_ContentMgr::SetDefaultDirectory();
};

bool ContentMgr::LoadAllContent()
{
	LoadContentMap<Texture>("Textures", textureMap);
	//LoadContentMap<Sound>("Sounds", soundMap);
	
	return true;
};

void ContentMgr::UnloadAllContent()
{
	textureMap->clear();
	soundMap->clear();
}

template<typename T>
T* ContentMgr::LoadContent(const std::string file)
{
	throw ContentLoadException(file);
};

template<>
Texture* ContentMgr::LoadContent<Texture>(const std::string file)
{
	// If mapping does exists, return map value.
	// Otherwise, load content from file system.
	if (textureMap->find(file) != textureMap->end())
	{
		return textureMap->at(file);
	}
	else
	{
		std::string pathfilename = GFRAL_ContentMgr::GetContentDirectory("Textures") + file;

		try
		{
			ALLEGRO_BITMAP* bitmap = GFRAL_ContentMgr::CreateBitmap(pathfilename.c_str());
			Texture* texture = new Texture(bitmap);

			textureMap->insert(std::pair<const std::string, Texture*>(file, texture));
			return texture;
		}
		catch (ContentLoadException& e)
		{
			GFR_AL::PrintConsole(e.getMessage().c_str());

			// TEMP: To satisfy return until better solution found.
			assert(NULL);
			return NULL;
			// TEMP.
		}
	}
};

template<>
Sound* ContentMgr::LoadContent<Sound>(const std::string file)
{
	// If mapping does exists, return map value.
	// Otherwise, load content from file system.
	if (soundMap->find(file) != soundMap->end())
	{
		return soundMap->at(file);
	}
	else
	{
		std::string pathfilename = GFRAL_ContentMgr::GetContentDirectory("Sounds") + file;

		try
		{
			ALLEGRO_SAMPLE* sample = GFRAL_ContentMgr::CreateSample(pathfilename.c_str());
			Sound* sound = new Sound(sample);

			soundMap->insert(std::pair<const std::string, Sound*>(file, sound));
			return sound;
		}
		catch (ContentLoadException& e)
		{
			GFR_AL::PrintConsole(e.getMessage().c_str());

			// TEMP: To satisfy return until better solution found.
			assert(NULL);
			return NULL;
			// TEMP.
		}
	}
};

template<typename T>
void ContentMgr::UnloadContent(const std::string file)
{
	return ContentUnLoadException(file);
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

// TODO: Figure out how to pass in different template maps as parameters.
template <typename T>
void ContentMgr::LoadContentMap(const std::string subFolder, boost::unordered_map<std::string, T*>* map)
{
	std::string contentPathDir = GFRAL_ContentMgr::GetContentDirectory(subFolder.c_str());
	fs::recursive_directory_iterator end;
	fs::recursive_directory_iterator rdi(contentPathDir);

	while (rdi != end)
	{
		const std::string path = rdi->path().string();

		try
		{
			// TODO fix this line to be more flexible & cross-platform.
			// Plus 1 to the substr to get rid of directory separator for key.
			const std::string key = path.substr(path.rfind(subFolder) + subFolder.length() + 1, path.length() - 1);
			
			T* content = LoadContent<T>(key);
			map->insert(std::pair<const std::string, T*>(key, content));
			T* t = map->at(key);

			++rdi;
		}
		catch (fs::filesystem_error)
		{
			rdi.no_push();
			++rdi;
		}
		catch (ContentLoadException& e)
		{
			GFR_AL::PrintConsole(e.getMessage().c_str());
			++rdi;
		}
	}
};