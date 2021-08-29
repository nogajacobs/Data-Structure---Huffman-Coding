# Data-Structure---Huffman-Coding
#pragma once
#include <iostream>
//#include <sstream>
//#include <fstream>
#include <queue>
#include <list>
#include <string>
using namespace std;
class compareNode;
class HNode
{//a node of a leave or a node of a subtree.
public:
	char str;
	int frq;
	HNode* left;
	HNode* right;

	HNode() { str = ' '; frq = 0; left = NULL; right = NULL; } //???
	HNode(char s, int n) { str = s; frq = n; }
	friend class compareNode;
};

class compareNode
{
public:
	HNode* n;
	/*constexpr*/ bool operator()(HNode* const& n1, HNode* const& n2) /*const*/
	{
		return (n1->frq > n2->frq);
	}
};
