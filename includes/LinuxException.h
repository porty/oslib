#pragma once

#ifndef _WIN32

#include "UavException.h"

#include <string>

/**
 * An exception thrown by a linux system call.
 *
 * @author Shorty
 */
class LinuxException: public UavException
{
public: // static stuff
	static std::string makeMessage();
	static std::string makeMessage(const char * const str);

public:
	/**
	 * Create a new LinuxException. Will take the error code from the system.
	 */
	LinuxException(): UavException(makeMessage()) {};

	/**
	 * Create a new LinuxException. Will take the error code from the system,
	 * and use the supplied string for output.
	 *
	 * @param extraInfo Extra information about the error
	 */
	LinuxException(const char * const extraInfo): UavException(makeMessage(extraInfo)) {};

	/**
	 * The Linux error code.
	 *
	 * @return the linux error code
	 */
	int getErrorCode() const;
private:
	std::string message;
};

#endif
