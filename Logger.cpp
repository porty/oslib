#include "Logger.h"
#include "Thread.h"

#include <string>
#include <iostream>
#include <sstream>

using namespace UAV;

const std::string Logger::SEVERITY_NAMES[] = {	"[DEBUG] ",
												"[INFO]  ",
												"[WARN]  ",
												"[ERROR] ",
												"[FATAL] "};

Logger::Logger(const std::string & name, const Severity minSeverity)
	: minSeverity(minSeverity), name(name)
{
	
}

void Logger::log(const Severity severity, const std::string & message)
{
	// [WARN] [deadbeef] Logger.cpp: Dogs like to rofl
	if (severity >= minSeverity)
	{// TODO: log time + date
		std::stringstream text;
		text << SEVERITY_NAMES[severity] << "[" << std::hex;
		text.fill('0');
		text.width(8);
		text << OS::Thread::getCurrentThreadId();
		text.width(0);
		text << "] " << name << ": " << message << std::endl;
		std::cout << text.str();
	}
}

void Logger::log(const Severity severity, const std::string & message, const std::exception & ex)
{
	if (severity >= minSeverity)
	{
		std::stringstream text;
		text << message << std::endl << "Exception message: " << ex.what();
		log(severity, text.str());
	}
}
