# Data-Structure---Huffman-Coding
#include "HuffmanTree.h"
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "Huffman.h"
#include <string>

void huffmanTree::buildTree(string word)
{
	priority_queue<HNode*, vector<HNode*>, compareNode> q = buildTableOfFreq(word);
	HNode *h1, *h2;
	while (q.size()>1 )
	{
		h1 = q.top();
		q.pop();
		h2 = q.top();
		q.pop();
		HNode* hn = new HNode(' ', h1->frq + h2->frq);
		/*if (h2->str == "" || h1->str == "")
		{*/
			hn->left = h1;
			hn->right = h2;
		/*}
		else
		{
			hn->left = h2;
			hn->right = h1;
		}*/
		q.push(hn);
	}
	root = q.top();
	printLtrOrder(root);
	cout << endl;
	printTreeStruct(root);
	cout << endl;
	string arr[126];
	TreeCode(root, "",arr);
	for (int i = 0; i < word.length(); i++)
	{
		cout << arr[word[i]];
	}
	cout << endl;

}
priority_queue<HNode*, vector<HNode*>, compareNode> huffmanTree::buildTableOfFreq(string str)
{
	int counter = 0;
	priority_queue<HNode*, vector<HNode*>, compareNode >  q;
	priority_queue<HNode*, vector<HNode*>, compareNode >  q2;
	//string s = "";
	int table[126] = { 0 };
	for (int i = 0; i < str.length(); i++)
	{
		table[(char)str[i]]++; 
	}
	for (int i = 0; i < 126; i++)
	{
		if (table[i] > 0)
		{
			q.push(new HNode(/*s + */(char)i, table[i]));
			counter++;
		}
	}
	cout << counter<<endl; //print the different chars number
	return q;
}
void huffmanTree::printLtrOrder(HNode* node)
{
	if (node == NULL)
		return;
	/* first print data of node */
	if (node->left == NULL && node->right == NULL) //leaf
	{
		cout << node->str;
	}
	/* then recur on left subtree */
	printLtrOrder(node->left);

	/* now recur on right subtree */
	printLtrOrder(node->right);
}
void huffmanTree::printTreeStruct(HNode* node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	if (node->left == NULL && node->right == NULL) //leaf
	{
		cout << "1";
	}
	else
		cout << "0";
	/* then recur on left subtree */
	printTreeStruct(node->left);

	/* now recur on right subtree */
	printTreeStruct(node->right);
}
void huffmanTree::TreeCode(HNode* node,string s, string arr[])
{
	if (node == NULL)
		return;

	if (node->left == NULL && node->right == NULL) //leaf
	{
		arr[(int)(node->str)] = s;
		s.substr(0, s.length() - 1); 
		return;
	}

	/*recur on left subtree */
	TreeCode(node->left,s+"0",arr);

	/*recur on right subtree */
	TreeCode(node->right, s + "1", arr);
}

void huffmanTree::encode(string letters, string treeStruct, string text)
{
	root = new HNode();
	buildTreeToEncode(root, letters, treeStruct); //building the tree
	string arr[126];
	TreeCode(root, "", arr);
	HNode* p = root;
	//string tmp="";
	while (text.length() > 0)
	{
		while (p->left!=NULL && p->right!=NULL)
		{
			if (text[0] == '1')
				p = p->right;
			else
				p = p->left;
			//tmp += text[0];
			text=text.substr(1, text.length());
		}
		cout << p->str;
		p = root;
		//tmp = "";
	}
	cout << endl;
}

void huffmanTree::buildTreeToEncode(HNode* node, string &letters, string &treeStruct)
{
	if (treeStruct[0] == '0')
	{
		node->left = new HNode();
		node->right = new HNode();
		treeStruct = treeStruct.substr(1, treeStruct.length());
		buildTreeToEncode(node->left,letters,treeStruct);
		//treeStruct = treeStruct.substr(1, treeStruct.length());
		buildTreeToEncode(node->right, letters, treeStruct);
	}
	else //==1
	{
		node->str = letters[0];
		letters=letters.substr(1, letters.length());
		treeStruct = treeStruct.substr(1, treeStruct.length());
	}
}
