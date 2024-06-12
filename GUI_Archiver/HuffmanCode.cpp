#include "HuffmanCode.h"

map<unsigned char, string> HuffmanCode::GetHuffmanCode(Node* root)
{
	map<unsigned char, string> huffmanCode;
	CreateHuffmanCode(root, "", huffmanCode);
	return huffmanCode;
}
map<string, unsigned char> HuffmanCode::GetReverseHuffmanCode(Node* root)
{
	map<unsigned char, string>&& huffmanCode = GetHuffmanCode(root);
	map<string, unsigned char> reverseMap;

	for (auto& i : huffmanCode)
	{
		reverseMap.insert(make_pair(i.second, i.first));
	}

	return reverseMap;
}
void HuffmanCode::CreateHuffmanCode(Node* root, string str, map<unsigned char, string>& huffmanCode)
{
	if (root == nullptr) {
		return;
	}
	if (!root->left && !root->right) {
		huffmanCode[root->value] = str;
	}

	CreateHuffmanCode(root->left, str + "0", huffmanCode);
	CreateHuffmanCode(root->right, str + "1", huffmanCode);
}