#include "FileSystemTest.h"

#include "FileSystem.h"

#include <iostream>

using namespace OS;

void testExist()
{
	// touch testfile1.a
	// touch testfile2.a
	// touch testfile3.b
	// touch testfile4.b
	// touch testfile5
	// mkdir testdir1

	// file exists or not
	if (!FileSystem::fileExists("testfile1.a"))
	{
		throw std::exception("Can't find file testfile1.a");
	}

	if (FileSystem::fileExists("fakefile.a"))
	{
		throw std::exception("Found non-existant file fakefile.a");
	}

	// dir exists or not
	if (!FileSystem::directoryExists("testdir1"))
	{
		throw std::exception("Can't find dir");
	}
	if (FileSystem::directoryExists("fakeDir1"))
	{
		throw std::exception("Found non-existant dir");
	}

	// don't get confused between files and dirs
	if (FileSystem::fileExists("testdir1"))
	{
		throw std::exception("Found dir as file");
	}
	if (FileSystem::directoryExists("testfile1.a"))
	{
		throw std::exception("Found file as dir");
	}
	std::cout << "testExist() OK" << std::endl;
}

void testFileSystem()
{
	testExist();
}
