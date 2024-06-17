#include "Logger.h"

Logger::Logger(string pathForLogFile)
{
	logFile = new ofstream(pathForLogFile, ios::out | ios::app);
}
Logger::~Logger()
{
	logFile->close();
	delete logFile;
}
void Logger::Success(string succsesMessage)
{
	(*logFile) << __TIME__ << " Success!\n" << succsesMessage;
}
void Logger::Error(string errorMessage)
{
	(*logFile) << __TIME__ << " Error!\n" << errorMessage;
}
void Logger::Warning(string warningMessage)
{
	(*logFile) << __TIME__ << " Warning!\n" << warningMessage;
}
void Logger::Fatal(string fatalMessage)
{
	(*logFile) << __TIME__ << " Fatal!\n" << fatalMessage;
}
Logger& Logger::operator<<(string nothingText)
{
	(*logFile) << nothingText;
	return *this;
}