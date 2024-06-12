#pragma once
#include <fstream>

using namespace std;

class Logger
{
	ofstream* logFile;
public:
	Logger() = delete;
	Logger(string& pathForLogFile);
	virtual ~Logger();

	virtual void Success(string& succsesMessage);
	virtual void Warning(string& warningMessage);
	virtual void Error	(string& errorMessage);
	virtual void Fatal	(string& fatalMessage);

	Logger& operator<<(string nothingText);
};