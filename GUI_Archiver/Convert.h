#pragma once
#include <bitset>

using namespace std;

class Convert 
{
public:
	Convert() {}
	virtual ~Convert(){}

	static char		BinarySequenceToByte	(const string& binarySequence);
	static string	ByteToBinarySequence	(const char& byte);
	static string	BinarySequenceToSetBytes(const string& binaryFileText);
	static string	StringToBinarySequence	(const string& text);
};