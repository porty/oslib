#ifdef _WIN32
#include "Win32Exception.h"

#include <Windows.h>

char * OS::Win::Win32ExceptionHelper::failErrorMessage = "Failed to get error message from system";

OS::Win::Win32ExceptionHelper::~Win32ExceptionHelper()
{
	// be free, memory!
	ungetErrorMessage(errorString);
}

char * OS::Win::Win32ExceptionHelper::getErrorMessage(int code)
{
	// we will ask windows to allocate the memory for us. for that, we have to
	// give the function a pointer to a char *, not just a char *, so we have
	// to cast it to a char * to fit the function signature
	char * buf = NULL;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, code, 0, reinterpret_cast<char *>(&buf), 0, NULL);

	// fall back to using failErrorMessage if format message call failed
	return buf ? buf : failErrorMessage;
}

void OS::Win::Win32ExceptionHelper::ungetErrorMessage(char * str)
{
	// don't try to free memory if it's failErrorMessage (or null)
	if (str && (str != failErrorMessage))
	{
		LocalFree(str);
	}
}


OS::Win::Win32Exception::Win32Exception()
	: Win32ExceptionHelper(GetLastError())
{

}

OS::Win::Win32Exception::Win32Exception(int errorCode)
	: Win32ExceptionHelper(errorCode)
{

}
#endif
