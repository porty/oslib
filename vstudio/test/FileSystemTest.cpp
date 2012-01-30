#include "FileSystemTest.h"

#include "FileSystem.h"

#include <iostream>

using namespace OS;

void testA()
{
	std::cout << "main.cpp file? " << (FileSystem::fileExists("main.cpp") ? "true" : "false") << std::endl <<
		"main.cpp dir? " << (FileSystem::directoryExists("main.cpp") ? "true" : "false") << std::endl;
	std::cout << "Debug file? " << (FileSystem::fileExists("Debug") ? "true" : "false") << std::endl <<
		"Debug dir? " << (FileSystem::directoryExists("Debug") ? "true" : "false") << std::endl;
}

void testFileSystem()
{
	testA();
	std::cout << FileSystem::getCurrentDirectory() << std::endl;
}
