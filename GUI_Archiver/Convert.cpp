#include "Convert.h"

char	Convert::binarySequenceToByte(const string& binarySequence)
{
	bitset<8> byte(binarySequence);

	return static_cast<char>(byte.to_ulong());
}
string	Convert::byteToBinarySequence(const char& byte)
{
	bitset<8> binarySequence(byte);
	return binarySequence.to_string();
}
string	Convert::binarySequenceToSetBytes(const string& binaryFileText)
{
	char zeroBitCounter = '0';
	string byteInString = "",
		binaryTextInByte = "";

	for (const char& i : binaryFileText)
	{
		byteInString += i;
		if (byteInString.size() == 8)
		{
			binaryTextInByte += binarySequenceToByte(byteInString);
			byteInString = "";
		}
	}

	while (byteInString.size() != 0 && byteInString.size() != 8)
	{
		byteInString += '0';
		++zeroBitCounter;
	}
	if (!byteInString.empty())
	{
		binaryTextInByte += binarySequenceToByte(byteInString);
	}
	return zeroBitCounter + binaryTextInByte;
}
string	Convert::stringToBinarySequence(const string& text)
{
	string binarySequence = string();
	for (char ch : text)
	{
		binarySequence += byteToBinarySequence(ch);
	}
	return binarySequence;
}