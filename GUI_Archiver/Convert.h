#pragma once

#include <bitset>

using namespace std;

class Convert 
{
public:
	Convert() {}
	virtual ~Convert(){}

	static char		binarySequenceToByte(const string& binarySequence);
	static string	byteToBinarySequence(const char& byte);

	static string	binarySequenceToSetBytes(const string& binaryFileText);
	static string	stringToBinarySequence(const string& text);
} Convert;