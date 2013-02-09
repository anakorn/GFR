#include "ContentMgr.h"
#include "GFR_AL.h"
#include "ContentLoadException.h"
#include "ContentUnloadException.h"

namespace fs = boost::filesystem;

boost::unordered_map<std::string, Texture&>* ContentMgr::textureMap = new boost::unordered_map<std::string, Texture&>();
boost::unordered_map<std::string, Sound&>* ContentMgr::soundMap = new boost::unordered_map<std::string, Sound&>();

// Change working directory path to go straight
// to assets folder to minimize key length.
void ContentMgr::Initialize()
{
	framework::GFR_AL::SetDefaultDirectory();
};

bool ContentMgr::LoadAllContent()
{
	LoadContentMap<Texture>("Textures", textureMap);
	LoadContentMap<Sound>("Sounds", soundMap);
	
	return true;
};

void ContentMgr::UnloadAllContent()
{
	textureMap->clear();
	soundMap->clear();
}

template<typename T>
T& ContentMgr::LoadContent(const std::string file)
{
	throw ContentLoadException(file);
};

template<>
Texture& ContentMgr::LoadContent<Texture>(const std::string file)
{
	// If mapping does exists, return map value.
	// Otherwise, load content from file system.
	if (textureMap->find(file) != textureMap->end())
	{
		return textureMap->at(file);
	}
	else
	{
		std::string path = framework::GFR_AL::GetContentDirectory("Textures") + file;

		try
		{
			Texture* content = new Texture(path.c_str());

			textureMap->insert(std::pair<const std::string, Texture&>(file, *content));
			return *content;
		}
		catch(ContentLoadException& e)
		{
			framework::GFR_AL::PrintConsole(e.getMessage().c_str());

			// TEMP: To satisfy return until better solution found.
			Texture* content = new Texture(path.c_str());
			return *content;
			// TEMP.
		}
	}
};

template<>
Sound& ContentMgr::LoadContent<Sound>(const std::string file)
{
	// If mapping does exists, return map value.
	// Otherwise, load content from file system.
	if (soundMap->find(file) != soundMap->end())
	{
		Sound& sound = soundMap->at(file);
		return sound;
	}
	else
	{
		std::string path = framework::GFR_AL::GetContentDirectory("Sounds") + file;

		try
		{
			Sound* content = new Sound(path.c_str());

			soundMap->insert(std::pair<const std::string, Sound&>(file, *content));
			return *content;
		}
		catch(ContentLoadException& e)
		{
			framework::GFR_AL::PrintConsole(e.getMessage().c_str());

			// TEMP: To satisfy return until better solution found.
			Sound* content = new Sound(path.c_str());
			return *content;
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
void ContentMgr::LoadContentMap(const std::string subFolder, boost::unordered_map<std::string, T&>* map)
{
	fs::recursive_directory_iterator end;
	fs::recursive_directory_iterator rdi(framework::GFR_AL::GetContentDirectory(subFolder));

	while (rdi != end)
	{
		const std::string path = rdi->path().string();

		try
		{
			T* content = new T(path.c_str());
			// TODO fix this line to be more flexible & cross-platform.
			// Plus 1 to the substr to get rid of directory separator for key.
			const std::string key = path.substr(path.rfind(subFolder) + subFolder.length() + 1, path.length() - 1);
			map->insert(std::pair<const std::string, T&>(key, *content));

			++rdi;
		}
		catch(fs::filesystem_error)
		{
			rdi.no_push();
			++rdi;
		}
		catch(ContentLoadException& e)
		{
			framework::GFR_AL::PrintConsole(e.getMessage().c_str());
			++rdi;
		}
	}
};