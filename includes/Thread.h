#pragma once

#include <stdint.h>

namespace OS
{

	class Thread
	{
	public: // static
		/**
		 * Get the ID of the current thread.
		 *
		 * @return The ID of the current thread.
		 */
		static int getCurrentThreadId();

		/**
		 * Sleep the current thread for a specified amount of time.
		 *
		 * @param milliseconds The number of milliseconds to sleep for
		 */
		static void sleep(int milliseconds);
	public: // non-static
		/**
		 * Create a new thread.
		 */
		Thread();

		/**
		 * Start the thread.
		 */
		void start();

		/**
		 * Wait for the thread to finish.
		 */
		void join();

		/**
		 * Wait for the thread to finish, or timeout.
		 *
		 * @param timeout Timeout time in milliseconds.
		 * @return True if thread finished, false if timed out.
		 */
		bool join(int timeout);

	private:
		/**
		 * The thread entry point function.
		 *
		 * @param obj The Thread object to run
		 */
		static void entryPoint(void * const obj);

		/**
		 * The thread ID for this thread. Might not be needed.
		 */
		unsigned long threadId;

		/**
		 * The handle of the thread.
		 */
#ifdef _WIN32
		void * handle;
#else
		unsigned long handle;
#endif

		/**
		 * The method the implementing class must implement. This is run when a
		 * thread starts.
		 */
		virtual void run() = 0;
	};

}
