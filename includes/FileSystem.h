#pragma once

#include "macros.h"

#include <string>
#include <list>

namespace OS
{
	class FileSystem
	{
	public:
		/**
		 * List a bunch of files in a directory, given a particular criteria.
		 *
		 * @param directory The directory to list
		 * @param filter The filename filter (i.e. *.jpg)
		 * @param createdAfter Only list files after this created time
		 * @param files [out] The list of found files
		 */
		static void getFileListing(const std::string & directory, const
			std::string & filter, const time_t createdAfter,
			std::list<std::string> & files);

		static bool fileExists(const std::string & name);

		static bool directoryExists(const std::string & name);

		static const std::string & getDirectorySeparator()	{ return directorySeparator; }

		/**
		 * Get the name only portion of a given path.
		 *
		 * @param path The full path filename, i.e. "C:\stuff\file.exe"
		 * @return The filename portion, i.e. "file.exe"
		 */
		static std::string nameOnly(const std::string & path);

		static std::string getCurrentDirectory();

	private:
		static const std::string directorySeparator;

	private: // not to be implemented
		FileSystem();
		NO_COPY_CONSTRUCTOR(FileSystem);
		NO_ASSIGNMENT_OPERATOR(FileSystem);
	};
}
