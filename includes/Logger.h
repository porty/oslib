#pragma once

#include "macros.h"

#include <string>

namespace UAV
{
	class Logger
	{
	public:
		/**
		 * The log severity type.
		 */
		typedef enum { DEBUG, INFO, WARNING, ERROR, FATAL } Severity;

		/**
		 * Create a new logger instance.
		 *
		 * @param name The name of the logger instance. Usually the filename of
		 * the c++ file
		 * @param minSeverity The minimum severity level logged
		 */
		Logger(const std::string & name, const Severity minSeverity);

		/**
		 * Log a message.
		 *
		 * @param severity The severity of the log message
		 * @param message The log message
		 */
		void log(const Severity severity, const std::string & message);

		/**
		 * Log a message.
		 *
		 * @param severity The severity of the log message
		 * @param message The log message
		 * @param ex The exception
		 */
		void log(const Severity severity, const std::string & message, const std::exception & ex);

	private:
		static const std::string SEVERITY_NAMES[];
		const Severity minSeverity;
		const std::string name;

	private: // not to be implemented
		NO_COPY_CONSTRUCTOR(Logger);
		NO_ASSIGNMENT_OPERATOR(Logger);
	};
}
