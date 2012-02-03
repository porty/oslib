#pragma once

#ifndef _WIN32

#include <exception>
#include <string>

/**
 * An exception thrown by a linux system call.
 *
 * @author Shorty
 */
class LinuxException: public std::exception
{
public: // static stuff
	static std::string makeMessage();
	static std::string makeMessage(const char * const str);

public:
	/**
	 * Create a new LinuxException. Will take the error code from the system.
	 */
	LinuxException(): message(makeMessage()) {}

	/**
	 * Create a new LinuxException. Will take the error code from the system,
	 * and use the supplied string for output.
	 *
	 * @param extraInfo Extra information about the error
	 */
	LinuxException(const char * const extraInfo): message(makeMessage(extraInfo)) {}

	~LinuxException() throw() {}

	/**
	 * The Linux error code.
	 *
	 * @return the linux error code
	 */
	int getErrorCode() const;

	virtual const char * what() const throw() { return message.c_str(); }
private:
	std::string message;
};

#endif
