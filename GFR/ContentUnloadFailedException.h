#ifndef GFR_FRAMEWORK_EXCEPTIONS_CONTENTUNLOADFAILEDEXCEPTION_H
#define GFR_FRAMEWORK_EXCEPTIONS_CONTENTUNLOADFAILEDEXCEPTION_H

#include <string>

class ContentUnLoadFailedException
{
public:
	ContentUnLoadFailedException(const char* fileName, const char* message)
		:fileName(fileName), message(message) 
	{};

private:
	std::string fileName;
	std::string message;
};

#endif