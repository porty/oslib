#include "AtomicInt32.h"

using namespace OS;

#ifdef _WIN32
#include <Windows.h>
#else
#include <atomic_ops.h>
#endif

unsigned long AtomicInt32::operator ++()
{
#ifdef _WIN32
	return InterlockedIncrement(&value);
#else
	return AO_fetch_and_add1(&value);
#endif
}

unsigned long AtomicInt32::operator --()
{
#ifdef _WIN32
	return InterlockedDecrement(&value);
#else
	return AO_fetch_and_sub1(&value);
#endif
}

