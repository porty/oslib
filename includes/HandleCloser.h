#pragma once

#ifdef _WIN32

#include "macros.h"

#include <Windows.h>

namespace OS { namespace Win
{

	/**
	 * Ensures a windows handle is closed when class goes out of scope.
	 *
	 * @author Shorty
	 */
	class HandleCloser
	{
	public:
		/**
		 * Create new handle closer.
		 *
		 * @param handle The handle to close when going out of scope. Will also
		 * set to INVALID_HANDLE_VALUE when the time comes just to make sure
		 */
		HandleCloser(HANDLE & handle): handle(handle) {}

		/**
		 * Destructor. This does the handle closing
		 */
		~HandleCloser()
		{
			close(handle);
		}

	public: //static
		/**
		 * Close a given handle (if not invalid) and set to invalid.
		 *
		 * @param handle The handle to close and set
		 */
		static void close(HANDLE & handle)
		{
			if (handle != INVALID_HANDLE_VALUE)
			{
				CloseHandle(handle);
				handle = INVALID_HANDLE_VALUE;
			}
		}
	private:
		/** The handle (reference). */
		HANDLE & handle;
	private:
		NO_COPY_CONSTRUCTOR(HandleCloser);
		NO_ASSIGNMENT_OPERATOR(HandleCloser);
	};

	/**
	 * Class that can be used in place of an actual Windows HANDLE. Automatically
	 * closes the handle when done.
	 *
	 * @author Shorty
	 */
	class Handle
	{
	public:
		Handle(): handle(INVALID_HANDLE_VALUE) {}

		~Handle() { HandleCloser::close(handle); }

		operator HANDLE() { return get(); }

		Handle & operator = (const HANDLE & value) { set(value); return *this; };

		bool operator == (const HANDLE & rhs) const { return handle == rhs; }

		HANDLE get() const { return handle; }
		void set(HANDLE value) { handle = value; }

		bool isValid() const { return !isInvalid(); }
		bool isInvalid() const { return handle == INVALID_HANDLE_VALUE; }
	private:
		HANDLE handle;
	private:
		NO_COPY_CONSTRUCTOR(Handle);
		NO_ASSIGNMENT_OPERATOR(Handle);
	};

} }

#endif
