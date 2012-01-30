#include <iostream>

#include "AtomicInt32Test.h"
#include "FileSystemTest.h"

int main()
{
	try
	{
		//testAtomicInt32();
		testFileSystem();
	}
	catch (const std::exception & ex)
	{
		std::cerr << ex.what() << std::endl;
		return -1;
	}
}
