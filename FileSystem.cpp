#include "FileSystem.h"

using namespace OS;

#ifdef _WIN32

#include "Win32Exception.h"
#include "FindHandle.h"

#include <Windows.h>

using namespace OS::Win;
const std::string OS::FileSystem::directorySeparator = "\\";
#else
const std::string OS::FileSystem::directorySeparator = "/";
#include <sys/stat.h>
#endif


#ifdef _WIN32

bool isAfter(const FILETIME & fileTime, const time_t & timeT)
{
	// http://blogs.msdn.com/b/oldnewthing/archive/2004/08/25/220195.aspx
	// http://support.microsoft.com/kb/188768
	// http://msdn.microsoft.com/en-us/library/windows/desktop/ms724290(v=vs.85).aspx
	// TODO
	//throw std::exception("not implemented");
	return true;
}

#endif

void FileSystem::getFileListing(const std::string & directory, const
		std::string & filter, const time_t createdAfter,
		std::list<std::string> & files)
{
	files.clear();
#ifdef _WIN32
	WIN32_FIND_DATAA findData;
	// super awesome Handle class that has super powers
	FindHandle handle;

	handle.set(FindFirstFile((directory + directorySeparator + filter).c_str(), &findData));
	if (!handle.isValid())
	{
		const int errorCode = GetLastError();
		if (errorCode == ERROR_FILE_NOT_FOUND)
		{
			// that's valid, no matching files were found
			return;
		}
		else
		{
			throw Win32Exception(errorCode);
		}
	}

	do
	{
		if (isAfter(findData.ftCreationTime, createdAfter))
		{
			files.push_back(findData.cFileName);
		}
	}
	while (FindNextFile(handle.get(), &findData));
#else
	// TODO not implemented
	#pragma message("Not implemented")
#endif
}

bool FileSystem::fileExists(const std::string & fileName)
{
#ifdef _WIN32
	DWORD attribs = GetFileAttributes(fileName.c_str());
	if (attribs == INVALID_FILE_ATTRIBUTES)
	{
		return false;
	}
	return (attribs & FILE_ATTRIBUTE_DIRECTORY) == 0;
#else
	struct stat statInfo;
	stat(fileName.c_str(), &statInfo);
	return S_ISREG(statInfo.st_mode);
#endif
}

bool FileSystem::directoryExists(const std::string & dirName)
{
#ifdef _WIN32
	DWORD attribs = GetFileAttributes(dirName.c_str());
	if (attribs == INVALID_FILE_ATTRIBUTES)
	{
		return false;
	}
	return (attribs & FILE_ATTRIBUTE_DIRECTORY) != 0;
#else
	struct stat statInfo;
	stat(dirName.c_str(), &statInfo);
	return S_ISDIR(statInfo.st_mode);
#endif
}

std::string FileSystem::nameOnly(const std::string & path)
{
	std::string::size_type index = path.find_last_of(directorySeparator[0]);
	if (index == std::string::npos)
	{
		// no slash found
		return path;
	}
	else if (index == (path.length() - 1))
	{
		// slash was the last character
		return "";
	}
	else
	{
		return path.substr(index + 1);
	}
}

std::string FileSystem::getCurrentDirectory()
{
#ifdef _WIN32
	char buffer[MAX_PATH + 1];
	int length = GetCurrentDirectory(sizeof(buffer), buffer);
	if (length == 0)
	{
		throw Win32Exception();
	}
	return buffer;
#else
	// TODO not implemented
	#pragma message("Not implemented")
	return ".";
#endif
}
