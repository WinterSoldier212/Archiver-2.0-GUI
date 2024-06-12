#include "HuffmanCode.h"

map<unsigned char, string> HuffmanCode::getHuffmanCode(Node* root)
{
	map<unsigned char, string> huffmanCode;
	createHuffmanCode(root, "", huffmanCode);
	return huffmanCode;
}
map<string, unsigned char> HuffmanCode::getReverseHuffmanCode(Node* root)
{
	map<unsigned char, string>&& huffmanCode = getHuffmanCode(root);
	map<string, unsigned char> reverseMap;

	for (auto& i : huffmanCode)
	{
		reverseMap.insert(make_pair(i.second, i.first));
	}

	return reverseMap;
}
void HuffmanCode::createHuffmanCode(Node* root, string str, map<unsigned char, string>& huffmanCode)
{
	if (root == nullptr) {
		return;
	}
	if (!root->left && !root->right) {
		huffmanCode[root->value] = str;
	}

	createHuffmanCode(root->left, str + "0", huffmanCode);
	createHuffmanCode(root->right, str + "1", huffmanCode);
}