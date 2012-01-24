#include "Settings.h"
#include "DirectoryScannerThread.h"
#include "FileSystem.h"
#include "Image.h"
#include "NetTransferQueue.h"
#include "HttpClient.h"
#include "UavException.h"

#include <iostream>

using namespace UAV;

void testLog();
void testImages();
void testSettings();
void testDirectoryScannerThread();
void testPostData();

#ifndef _WIN32
// sssh stop complaining
#define system(x)
#endif

int main()
{
	try
	{
		Settings::createGlobal();
		//testDirectoryScannerThread();
		testPostData();


	}
	catch (const UavException & ex)
	{
		std::cout << "UavException thrown: " << ex.what() << "\n";
	}
	catch (const std::exception & ex)
	{
		std::cout << "Exception thrown: " << ex.what() << "\n";
	}
	system("pause");

}

void testLog()
{
	Logger l("rofl", Logger::INFO);
	l.log(Logger::DEBUG, "This is debug");
	l.log(Logger::INFO, "This is info");
	l.log(Logger::WARNING, "This is warning");
	l.log(Logger::ERROR, "This is error");
	l.log(Logger::FATAL, "This is fatal");
	system("pause");
}

void testImages()
{
	try
	{
		Settings::createGlobal();

		std::cout << "Image directory - " << Settings::getGlobal().getImageDirectory() << "\n";
		Image image("20111016110000.jpg");
		std::cout << "Image path: " << image.getImageFilePath() << "\n" <<
			"Location path: " << image.getLocationFilePath() << "\n";
	}
	catch (const std::exception & ex)
	{
		std::cout << "Exception thrown: " << ex.what() << "\n";
	}
	system("pause");
}

void testSettings()
{
	Settings::createGlobal();

	Settings & s = Settings::getGlobal();

	std::cout << "Image directory: " << s.getImageDirectory() << "\n" <<
		"Image file suffix: " << s.getImageFileSuffix() << "\n" <<
		"Location file suffix: " << s.getLocationFileSuffix() << "\n"
		"Scanner sleep time: " << s.getScannerSleepTime() << "\n";
}

void testDirectoryScannerThread()
{/*
	NetTransferQueueMock ntqm;
	DirectoryScannerThread dst(ntqm);
	std::cout << "Starting Directory Scanner Thread. Hit something to stop.\n";
	dst.start();
	
	std::cin.get();
	std::cout << "Stopping...\n";

	dst.stop();
	dst.join();
*/
}

void testPostData()
{
	PostData postData;
	postData.addText("text1", "This is text one");
	postData.addText("text2", "This is text two");
	postData.addFile("text1_file", "testdata/test1.txt");
	postData.addFile("text2_file", "testdata/test2.txt");

	postData.generateMultipart(std::cout, "this-is-the-boundary");
}
