#include "AtomicInt32Test.h"

#include "AtomicInt32.h"
#include "Thread.h"

#include <iostream>
#include <exception>

using namespace OS;

class AtomicInt32IncrementThread: public Thread
{
public:
	AtomicInt32IncrementThread(AtomicInt32 & ai, int count): ai(ai), count(count) {}
protected:
	AtomicInt32 & ai;
	const int count;
	virtual void run();
private:
	AtomicInt32IncrementThread & operator=(const AtomicInt32IncrementThread &);
};

class AtomicInt32DecrementThread: public Thread
{
public:
	AtomicInt32DecrementThread(AtomicInt32 & ai, int count): ai(ai), count(count) {}
protected:
	AtomicInt32 & ai;
	const int count;
	virtual void run();
private:
	AtomicInt32DecrementThread & operator=(const AtomicInt32DecrementThread &);
};

void AtomicInt32IncrementThread::run()
{
	for (int i = 0; i < count; ++i)
	{
		++ai;
	}
}

void AtomicInt32DecrementThread::run()
{
	for (int i = 0; i < count; ++i)
	{
		--ai;
	}
}

void testAtomicInt32()
{
	AtomicInt32 i;
	//int size = 2147483642;
	int size = 50000000;
	AtomicInt32IncrementThread inc(i, size);
	AtomicInt32DecrementThread dec(i,  size - 2);
	inc.start();
	dec.start();
	inc.join();
	dec.join();
	if (++i != 3)
	{
		throw std::exception("testAtomicInt32 failed");
	}
	std::cout << "testAtomicInt32 OK" << std::endl;
}