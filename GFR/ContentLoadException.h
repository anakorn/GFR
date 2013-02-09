#ifndef GFR_FRAMEWORK_EXCEPTIONS_CONTENTLOADEXCEPTION_H
#define GFR_FRAMEWORK_EXCEPTIONS_CONTENTLOADEXCEPTION_H

#include <string>

class ContentLoadException
{
public:
	ContentLoadException(std::string fileName) :
		msg("File \"" + fileName + "\" not found.")
	{};

	std::string getMessage()
	{
		return msg;
	};

private:
	std::string msg;
};

#endif