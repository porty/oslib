#pragma once

#include "macros.h"

namespace OS
{

	class WaitObject
	{
	public:
		/** The handle type. */
#ifdef _WIN32
		typedef void * handle_t;
#else
		typedef int handle_t;
#endif
	
		/**
		 * Wait on a handle.
		 */
		static bool waitOnHandle(handle_t handle, int timeout);

		/**
		 * Create a new wait object.
		 */
		WaitObject();

		/**
		 * Wait on this object indefinatly.
		 */
		void wait();

		/**
		 * Wait on this object, given a timeout period.
		 *
		 * @param timeout The timeout period, in milliseconds
		 * @return True if wait object was triggered, false if wait timed out
		 */
		bool wait(int timeout);

		/**
		 * Fire the wait object. Wakes a thread waiting on it.
		 */
		void fire();

	private:
		handle_t handle;

	private: // not to be implemented
		NO_COPY_CONSTRUCTOR(WaitObject);
		NO_ASSIGNMENT_OPERATOR(WaitObject);
	};

}
