#include "Thread.h"
#include "WaitObject.h"

#ifdef _WIN32
#include "Win32Exception.h"
#include <Windows.h>
#else
#include <pthread.h>
#include <unistd.h>
#endif

#include <stdint.h>


using namespace OS;

#ifdef _WIN32
using namespace OS::Win;
#endif

int Thread::getCurrentThreadId()
{
#ifdef _WIN32
	return GetCurrentThreadId();
#else
	return pthread_self();
#endif
}

void Thread::sleep(int milliseconds)
{
#ifdef _WIN32
	Sleep(milliseconds);
#else
	usleep(milliseconds * 1000);
#endif
}

Thread::Thread()
	: threadId(0), handle(0)
{
#ifdef _WIN32
	handle = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(entryPoint),
		this, CREATE_SUSPENDED, &threadId);
	if (!handle)
	{
		throw Win32Exception();
	}
#endif
	// linux do nothing...
}

void Thread::start()
{
#ifdef _WIN32
	ResumeThread(handle);
#else
	typedef void *(*startroutine_t) (void *) ;
	int retval = pthread_create(&handle, NULL, (startroutine_t) Thread::entryPoint, (void *) this);
	if (retval != 0)
	{
		throw UavException("Failed to create thread - pthread_create() returned non-zero value");
	}
#endif
}

void Thread::join()
{
#ifdef _WIN32
	join(INFINITE);
#else
	pthread_join(handle, NULL);
#endif
}

bool Thread::join(int timeout)
{
#ifdef _WIN32
	return WaitObject::waitOnHandle(handle, timeout);
#else
	// http://www.kernel.org/doc/man-pages/online/pages/man3/pthread_tryjoin_np.3.html
	// egh!
	// 1) pthread_timedjoin_np is Non-Portable
	// 2) the time input is in a weird timespec structure
	// 3) the time input is a measure of time since epoch, not since call
	timespec ts;
	// add in the seconds since epoch!
	ts.tv_sec = time(NULL) + timeout / 1000;
	// TODO: should probably take nanosecond granularity of epoch time and
	// offset here
	ts.tv_nsec = (timeout % 1000) * 1000 * 1000;
	return pthread_timedjoin_np(handle, NULL, &ts) == 0;
#endif
}

void Thread::entryPoint(void * const obj)
{
	Thread & thread = *static_cast<Thread *>(obj);
	thread.run();
}

