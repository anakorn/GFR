#ifndef GFR_FRAMEWORK_EXCEPTIONS_CONTENTLOADFAILEDEXCEPTION_H
#define GFR_FRAMEWORK_EXCEPTIONS_CONTENTLOADFAILEDEXCEPTION_H

#include <string>

class ContentLoadFailedException
{
public:
	ContentLoadFailedException(const char* fileName, const char* message)
		:fileName(fileName), message(message) 
	{};

private:
	std::string fileName;
	std::string message;
};

#endif