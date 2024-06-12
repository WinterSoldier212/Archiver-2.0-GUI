#include "HuffmanTree.h"

Node*	HuffmanTree::GetHuffmanTree (vector<size_t>& byteWeights)
{
	multimap<int, Node*> tree_;

	char symbol;
	int byteWeight;

	for (int i = 0; i < 0x100; ++i)
	{
		if (byteWeights.at(i) != 0)
		{
			symbol = char(i);
			byteWeight = byteWeights.at(i);
			Node* node = new Node(symbol, false);

			auto element = make_pair(byteWeight, node);
			tree_.insert(element);
		}
	}

	while (tree_.size() > 1)
	{
		tree_.insert(GoTwoNodesIntoOne(tree_));
	}

	return tree_.begin()->second;
}
Node*	HuffmanTree::ConvertStringToHuffmanTree (string str)
{
	char zeroSymbol = str[0];
	vector<Node*> nodes;

	FillTreeNodesWithSymbols(str, nodes);

	Node* cur = nodes[0];
	auto it = nodes.begin(); it++;
	vector<Node*> zeroNodes;

	while (it != nodes.end())
	{
		Node* left = *it;
		cur->left = left;
		++it;

		if (it == nodes.end())
			break;

		Node* right = *it;
		cur->right = right;
		++it;

		if (it == nodes.end())
			break;

		if (left->isNode && right->isNode)
		{
			cur = left;
			zeroNodes.push_back(right);
		}
		else if (left->isNode && !right->isNode)
		{
			cur = left;
		}
		else if (!left->isNode && right->isNode)
		{
			cur = right;
		}
		else if (!left->isNode && !right->isNode && !zeroNodes.empty())
		{
			int lastElement = zeroNodes.size() - 1;
			cur = zeroNodes[lastElement];
			zeroNodes.pop_back();
		}
	}
	Node* root = nodes[0];

	return root;
}
string	HuffmanTree::ConvertHuffmanTreeToString	(Node* tree)
{
	string huffmanTreeInText = string(1, '\0');
	TranslateHuffmanTreeIntoText(tree, huffmanTreeInText);
	return huffmanTreeInText;
}
void	HuffmanTree::DeleteHuffmanTree (Node* tree)
{
	if (tree == nullptr) {
		return;
	}
	if (!tree->left && !tree->right) {
		DeleteHuffmanTree(tree->left);
	}
	DeleteHuffmanTree(tree->right);

	delete tree;
}
void	HuffmanTree::FillTreeNodesWithSymbols (string& str, vector<Node*>& nodes)
{
	Node* node;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] == '\\')
		{
			node = new Node(str[++i], false);
		}
		else if (str[i] == '\0')
		{
			node = new Node(str[i], true);
		}
		else
		{
			node = new Node(str[i], false);
		}
		nodes.push_back(node);
	}
}
void	HuffmanTree::TranslateHuffmanTreeIntoText (Node* root, string& huffmanTreeInText)
{
	if (root == nullptr)
		return;

	if (root->isNode)
	{
		Node* left = root->left;
		Node* right = root->right;

		if (!left->isNode && (left->value == '\0' || left->value == '\\'))
			huffmanTreeInText += '\\';
		huffmanTreeInText += left->value;

		if (!right->isNode && (right->value == '\0' || right->value == '\\'))
			huffmanTreeInText += '\\';
		huffmanTreeInText += right->value;

		TranslateHuffmanTreeIntoText(left, huffmanTreeInText);
		TranslateHuffmanTreeIntoText(right, huffmanTreeInText);
	}
}
Node*	HuffmanTree::GetAndDeleteElement (int& weight_, multimap<int, Node*>& tree)
{
	weight_ += tree.begin()->first;
	Node* element = tree.begin()->second;
	tree.erase(tree.begin());

	return element;
}
pair<int, Node*> HuffmanTree::GoTwoNodesIntoOne (multimap<int, Node*>& tree)
{
	int weight_ = 0;

	Node* left = GetAndDeleteElement(weight_, tree);
	Node* right = GetAndDeleteElement(weight_, tree);
	Node* node_ = new Node(left, right);

	return make_pair(weight_, node_);
}