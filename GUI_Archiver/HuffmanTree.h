#pragma once

#include <map>
#include <vector>
#include <string>

using namespace std;

struct Node
{
	char value = 0;
	bool isNode = true;
	Node* left = nullptr, * right = nullptr;

	Node(char x, bool isNode_)
		: value(x), isNode(isNode_)
	{}
	Node(Node* left, Node* right)
		: left(left), right(right)
	{}
};

class HuffmanTree final
{
public:
	HuffmanTree() = delete;
	HuffmanTree		operator()(HuffmanTree& huffmanTree) = delete;
	HuffmanTree		operator=(HuffmanTree& huffmanTree) = delete;
	
	static Node*	GetHuffmanTree				(vector<size_t>& byteWeights);
	static Node*	ConvertStringToHuffmanTree	(string str);
	static string	ConvertHuffmanTreeToString	(Node* tree);
	static void		DeleteHuffmanTree			(Node* tree);
protected:
	static void		FillTreeNodesWithSymbols	(string& str, vector<Node*>& nodes);
	static void		TranslateHuffmanTreeIntoText(Node* root, string& huffmanTreeInText);
	static Node*	GetAndDeleteElement			(int& weight_, multimap<int, Node*>& tree);
	static pair<int, Node*>	GoTwoNodesIntoOne	(multimap<int, Node*>& tree);
};