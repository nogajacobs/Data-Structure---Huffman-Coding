# Data-Structure---Huffman-Coding
#pragma once
#include "Huffman.h"
#include <queue>

class HuffmanTree
{
	HNode* root;
public:
	/*huffmanTree() {}
	~huffmanTree() { delete root; }*/
	priority_queue<HNode*, vector<HNode*>, compareNode> buildTableOfFreq(string str);
	void buildTree(string word);
	void printLtrOrder(HNode* node);
	void printTreeStruct(HNode* node);
	void TreeCode(HNode* node, string s, string arr[]);

	void encode(string letters, string treeStruct, string text);
	void buildTreeToEncode(HNode* node, string &letters, string &treeStruct);
};


