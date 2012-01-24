#ifndef _WIN32

#include "LinuxException.h"

#include <errno.h>
#include <sstream>

std::string LinuxException::makeMessage()
{
	std::stringstream ss;
	ss << "Linux error #" << errno;
	return ss.str();
}

std::string LinuxException::makeMessage(const char * const str)
{
	std::stringstream ss;
	ss << str << " " << makeMessage();
	return ss.str();
}

#endif
