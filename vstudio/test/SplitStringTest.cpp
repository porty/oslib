#include "SplitStringTest.h"

#include "SplitString.h"
#include <exception>
#include <list>
#include <sstream>
#include <iostream>

using namespace OS;

void testNoMax()
{
	std::string str("This is a string");
	std::list<std::string> parts;
	splitString(str, " ", parts);
	if (parts.size() != 4)
	{
		std::stringstream ss;
		ss << "Wrong number of parts. Expected 4, actual " << parts.size();
		throw std::exception(ss.str().c_str());
	}
	int count = 0;
	for (std::list<std::string>::const_iterator it = parts.begin(); it != parts.end(); ++it, ++count)
	{
		switch (count)
		{
		case 0:
			if (*it != "This")
				throw std::exception(("Expected 'This', actual '" + *it + "'").c_str());
			break;
		case 1:
			if (*it != "is")
				throw std::exception(("Expected 'is', actual '" + *it + "'").c_str());
			break;
		case 2:
			if (*it != "a")
				throw std::exception(("Expected 'a', actual '" + *it + "'").c_str());
			break;
		case 3:
			if (*it != "string")
				throw std::exception(("Expected 'string', actual '" + *it + "'").c_str());
			break;
		default:
			throw std::exception("unknown index");
		}
	}
}

void testMax()
{
	std::string str("This is a string");
	std::list<std::string> parts;
	splitString(str, " ", parts, 2);
	if (parts.size() != 2)
	{
		std::stringstream ss;
		ss << "Wrong number of parts. Expected 2, actual " << parts.size();
		throw std::exception(ss.str().c_str());
	}
	int count = 0;
	for (std::list<std::string>::const_iterator it = parts.begin(); it != parts.end(); ++it, ++count)
	{
		switch (count)
		{
		case 0:
			if (*it != "This")
				throw std::exception(("Expected 'This', actual '" + *it + "'").c_str());
			break;
		case 1:
			if (*it != "is a string")
				throw std::exception(("Expected 'is a string', actual '" + *it + "'").c_str());
			break;
		default:
			throw std::exception("unknown index");
		}
	}
}

void testSplitString()
{
	testNoMax();
	std::cout << "testNoMax OK" << std::endl;
	testMax();
	std::cout << "testMax OK" << std::endl;
}
