#include "AtomicInt32.h"

using namespace OS;

#ifdef _WIN32
#include <Windows.h>
#else
TODO: atomic int 32 includes
#endif

unsigned long AtomicInt32::operator ++()
{
#ifdef _WIN32
	return InterlockedIncrement(&value);
#else
	TODO: atomic int 32 increment
#endif
}

unsigned long AtomicInt32::operator --()
{
#ifdef _WIN32
	return InterlockedDecrement(&value);
#else
	TODO: atomic int 32 decrement
#endif
}

