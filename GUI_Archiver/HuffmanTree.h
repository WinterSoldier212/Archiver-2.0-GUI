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
	
	static Node*	getHuffmanTree				(vector<size_t> byteWeights);
	static Node*	convertStringToHuffmanTree	(string str);
	static string	convertHuffmanTreeToString	(Node* tree);
	static void		deleteHuffmanTree			(Node* tree);
protected:
	static void		fillTreeNodesWithSymbols	(string& str, vector<Node*>& nodes);
	static void		translateHuffmanTreeIntoText(Node* root, string& huffmanTreeInText);
	static Node*	getAndDeleteElement			(int& weight_, multimap<int, Node*>& tree);
	static pair<int, Node*>	goTwoNodesIntoOne	(multimap<int, Node*>& tree);
};