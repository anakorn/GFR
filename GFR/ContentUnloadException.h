#ifndef GFR_FRAMEWORK_EXCEPTIONS_CONTENTUNLOADEXCEPTION_H
#define GFR_FRAMEWORK_EXCEPTIONS_CONTENTUNLOADEXCEPTION_H

#include <string>

class ContentUnLoadException
{
public:
	ContentUnLoadException(std::string fileName) :
		msg("File \"" + fileName + "\" could not unload.")
	{};

	std::string getMessage()
	{
		return msg;
	};

private:
	std::string msg;
};

#endif