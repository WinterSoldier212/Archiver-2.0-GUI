#pragma once

#include "HuffmanTree.h"

class HuffmanCode
{
public:
	HuffmanCode() = delete;
	HuffmanCode operator()(HuffmanCode& huffmanCode) = delete;
	HuffmanCode operator=(HuffmanCode& huffmanCode)  = delete;

	static map<unsigned char, string> getHuffmanCode(Node* root);
	static map<string, unsigned char> getReverseHuffmanCode(Node* root);
protected:
	static void createHuffmanCode(Node* root, std::string str, std::map<unsigned char, string>& huffmanCode);
};