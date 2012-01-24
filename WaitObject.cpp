#include "WaitObject.h"

#ifdef _WIN32
#include "Win32Exception.h"
#include <Windows.h>
using namespace OS::Win;
#else
#include "LinuxException.h"
#include <sys/timerfd.h>
//#include <time.h>
#include <poll.h>

// I can't get things to work dammit!
#ifndef CLOCK_MONOTONIC
#define CLOCK_MONOTONIC 1
#endif

#endif

using namespace OS;

bool WaitObject::waitOnHandle(handle_t handle, int timeout)
{
#ifdef _WIN32
	int status = WaitForSingleObject(handle, timeout);
	switch (status)
	{
	case WAIT_OBJECT_0:
		return true;
	case WAIT_TIMEOUT:
		return false;
	case WAIT_ABANDONED:
		throw std::exception("Wait was abandoned");
	default:
		throw Win32Exception();
	}
#else
	// the poll information (POLL File Descriptor)
	pollfd pollinfo;
	pollinfo.fd = handle;
	pollinfo.events = 0;
	pollinfo.revents = 0;

	// the number of file descriptors (Number of File Descriptors)
	nfds_t nfds = 1;

	int result = poll(&pollinfo, nfds, timeout);
	if (result < 0)
	{
		// error
		// TODO: better exception messages for linux (i.e. error number)
		throw LinuxException("poll() called failed");
	}
	else if (result == 0)
	{
		// timeout
		return false;
	}
	else
	{
		// result should == 1 (the number of file descriptors with events
		return true;
	}
	//not implmented
	//maybe use select() or poll() with a file descriptor?
	//the file descriptor maybe made from http://linux.die.net/man/2/timerfd_create ?
#endif
}

WaitObject::WaitObject()
	: handle(0)
{
#ifdef _WIN32
	handle = CreateEvent(NULL, FALSE, FALSE, NULL);
	if (!handle)
	{
		throw Win32Exception();
	}
#else
	handle = timerfd_create(CLOCK_MONOTONIC, 0);
#endif
}

void WaitObject::wait()
{
#ifdef _WIN32
	wait(INFINITE);
#else
	wait(-1);
#endif
}

bool WaitObject::wait(int timeout)
{
	return waitOnHandle(handle, timeout);
}

void WaitObject::fire()
{
#ifdef _WIN32
	SetEvent(handle);
#else
	// TODO: not implemented
#endif
}
