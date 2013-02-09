#ifndef GFR_FRAMEWORK_MANAGERS_CONTENTMGR_CONTENTMGR_H
#define GFR_FRAMEWORK_MANAGERS_CONTENTMGR_CONTENTMGR_H

#include <map>
#include <string>
#include "Texture.h"
#include "Sound.h"
#include "ContentLoadFailedException.h"
#include "ContentUnloadFailedException.h"
#include "boost/filesystem.hpp"
#include "boost/unordered_map.hpp"

class ContentMgr
{
public:
	static void Initialize();
	
	// Loads all content in assets folder.
	static bool LoadAllContent();
	static void UnloadAllContent();

	// LoadContent() checks the corresponding
	// map for the filePath parameter as the key.
	template<typename T>
	static T& LoadContent(const std::string filePath);

	template<typename T>
	static void UnloadContent(const std::string file);

private:
	static boost::unordered_map<std::string, Texture&>* textureMap;
	static boost::unordered_map<std::string, Sound&>* soundMap;

	template <typename T>
	static void LoadContentMap(const std::string subFolder, boost::unordered_map<std::string, T&>* map);

};

#endif GFR_FRAMEWORK_MANAGERS_CONTENTMGR_CONTENTMGR_H
