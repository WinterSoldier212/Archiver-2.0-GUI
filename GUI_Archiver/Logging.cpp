#include "Logging.h"

Logging::Logging(string& pathForLogFile)
{
	logFile = new ofstream(pathForLogFile, ios::out | ios::app);
}
Logging::~Logging()
{
	logFile->close();
	delete logFile;
}
void Logging::Success(string& succsesMessage)
{
	(*logFile) << __TIME__ << " Success!\n" << succsesMessage;
}
void Logging::Error(string& errorMessage)
{
	(*logFile) << __TIME__ << " Error!\n" << errorMessage;
}
void Logging::Warning(string& warningMessage)
{
	(*logFile) << __TIME__ << " Warning!\n" << warningMessage;
}
void Logging::Fatal(string& fatalMessage)
{
	(*logFile) << __TIME__ << " Fatal!\n" << fatalMessage;
}