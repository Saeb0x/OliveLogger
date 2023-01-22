#include "Logger.h"

std::vector<logEntry> Logger::records;

std::string dateAndTimeAsString()
{
	std::time_t localTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::string output(30, '\0');
	std::strftime(&output[0], output.size(), "%d-%b-%Y %H:%M:%S", std::localtime(&localTime));
	return output;
}

void Logger::Info(const std::string& logInfo)
{
	logEntry logEntry;
	logEntry.type = LOG_INFO;

	std::string output = "INFO [" + dateAndTimeAsString() + "]: " + logInfo;
	logEntry.content = output;
	records.push_back(logEntry);

	std::cout << "\x1B[32m" << logEntry.content << "\033[0m" << std::endl; // Green info
}

void Logger::Warning(const std::string& logWarning)
{
	logEntry logEntry;
	logEntry.type = LOG_WARNING;

	std::string output = "WARNING [" + dateAndTimeAsString() + "]: " + logWarning;
	logEntry.content = output;
	records.push_back(logEntry);

	std::cout << "\x1B[93m" << logEntry.content << "\033[0m" << std::endl; // Yellow warnings
}

void Logger::Error(const std::string& logError)
{
	logEntry logEntry;
	logEntry.type = LOG_ERROR;

	std::string output = "ERROR [" + dateAndTimeAsString() + "]: " + logError;
	logEntry.content = output;
	records.push_back(logEntry);

	std::cout << "\x1B[91m" << output << "\033[0m" << std::endl; // Red errors
}