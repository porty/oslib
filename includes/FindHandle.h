#pragma once

#ifdef _WIN32

#include <Windows.h>
#include <exception>

namespace OS { namespace Win
{
	class FindHandle
	{
	public:
		FindHandle(): handle(INVALID_HANDLE_VALUE) {}
		~FindHandle()
		{
			if (isValid())
			{
				FindClose(handle);
			}
		}

		void set(HANDLE handle)
		{
			if (isValid())
			{
				throw std::exception("Cannot set a new value to this handle");
			}
			this->handle = handle;
		}

		HANDLE get()
		{
			return handle;
		}

		bool isValid() const { return handle != INVALID_HANDLE_VALUE; }

	private:
		HANDLE handle;
	};
} }

#endif
