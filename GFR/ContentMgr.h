#ifndef GFR_FRAMEWORK_MANAGERS_CONTENTMGR_CONTENTMGR_H
#define GFR_FRAMEWORK_MANAGERS_CONTENTMGR_CONTENTMGR_H

#include <map>
#include <string>
#include "Texture.h"
#include "Sound.h"
#include "ContentLoadFailedException.h"
#include "ContentUnloadFailedException.h"
#include "boost/filesystem.hpp"

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
	static T* LoadContent(const std::string filePath);

	template<typename T>
	static void UnloadContent(const std::string file);

private:
	static std::map<std::string, Texture*>* textureMap;
	static std::map<std::string, Sound*>* soundMap;

};

#endif GFR_FRAMEWORK_MANAGERS_CONTENTMGR_CONTENTMGR_H
