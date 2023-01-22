#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>

enum logType
{
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR
};

struct logEntry
{
	logType type;
	std::string content;
};

class Logger
{
public:
	static std::vector<logEntry> records;
	static void Info(const std::string& logInfo);
	static void Warning(const std::string& logWarning);
	static void Error(const std::string& logError);
};

