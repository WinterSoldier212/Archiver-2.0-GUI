#pragma once

#include "HuffmanTree.h"

class HuffmanCode
{
public:
	HuffmanCode() = delete;
	HuffmanCode operator()(HuffmanCode& huffmanCode) = delete;
	HuffmanCode operator=(HuffmanCode& huffmanCode)  = delete;

	static map<unsigned char, string> GetHuffmanCode(Node* root);
	static map<string, unsigned char> GetReverseHuffmanCode(Node* root);
protected:
	static void CreateHuffmanCode(Node* root, std::string str, std::map<unsigned char, string>& huffmanCode);
};