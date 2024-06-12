#pragma once
#include <fstream>

using namespace std;

class Logging
{
	ofstream* logFile;
public:
	Logging	(string& pathForLogFile);
	virtual ~Logging();

	virtual void Success(string& succsesMessage);
	virtual void Warning(string& warningMessage);
	virtual void Error	(string& errorMessage);
	virtual void Fatal	(string& fatalMessage);
} LogFile;