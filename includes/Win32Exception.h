#pragma once

#ifdef _WIN32

#include "macros.h"

#include <exception>

namespace OS { namespace Win
{

	/**
	 * Helper class so that a constuctor doesn't get initialisation of many
	 * parameters incorrect, and because C++ doesn't have "delegating
	 * constructors" just yet (unlike Java, grumble grumble...).
	 *
	 * @author Shorty
	 */
	class Win32ExceptionHelper: public std::exception
	{
	public:
		/**
		 * Clean up rubbish left by this.
		 */
		~Win32ExceptionHelper();
	
		/**
		 * Get the Win32 error code.
		 */
		int getErrorCode() const	{ return errorCode; };

		/**
		 * Actually return the error message.
		 */
		virtual const char * what() const { return errorString; }

	protected:
		/**
		 * Create a new Win32ExceptionHelper, specifying the error code.
		 *
		 * @param code The Win32 error code, usually from a call to GetLastError()
		 */
		Win32ExceptionHelper(int code):
		  errorCode(code), errorString(getErrorMessage(code)) {}

	private:
		/** the error code. */
		const int errorCode;

		/** the error string. */
		char * errorString;
		
	private: // static
		/**
		 * A default error message, if we cannot get one from windows.
		 */
		static char * failErrorMessage;

		/**
		 * Get a formatted error message from Windows.
		 *
		 * @param code The Win32 error code
		 * @return A formatted error string. Give to ungetErrorMessage() when
		 * done with it - do not try to free it yourself
		 */
		static char * getErrorMessage(int code);

		/**
		 * Frees a string allocated through getErrorMessage().
		 *
		 * @param str A string returned from a call to getErrorMessage()
		 */
		static void ungetErrorMessage(char * str);

	private:
		NO_ASSIGNMENT_OPERATOR(Win32ExceptionHelper);
	};

	/**
	 * Encapsulates an error as a result of a Win32 function call. Formats the
	 * error code in to a nice, user-friendly error message.
	 *
	 * @author Shorty
	 */
	class Win32Exception: public Win32ExceptionHelper
	{
	public:
		/**
		 * Create a new Win32Exception. This will grab the error code from Windows
		 */
		Win32Exception();

		/**
		 * Create a new Win32Exception. This will use the error code specifed
		 */
		Win32Exception(int errorCode);

	private: // not to be implemented
		//NO_COPY_CONSTRUCTOR(Win32Exception);
		NO_ASSIGNMENT_OPERATOR(Win32Exception);
	};

} }

#endif
