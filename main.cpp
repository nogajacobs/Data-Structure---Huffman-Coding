# Data-Structure---Huffman-Coding
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "huffmanTree.h"
#include "Huffman.h"
//Noga Oren 206970519
//Shira Orbach 315234484

int main()
{
	int choice, n, charCounter=0;
	string word, letters, codeStructure, text;
	int frequencyTable[256] = { 0 }; //256 chars in ASSCII
	string codedTable[256] = { "" };

	huffmanTree* t = new huffmanTree();
	cout << "enter 1 to encode a text\n";
	cout << "enter 2 to decode a text\n";
	cout << "enter 3 to exit\n";
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:

			cout << "enter the original text" << endl;
			cin >> word;
			cout << "The encoded string is :\n";
			t->buildTree(word);
			//Build Huffman tree given the data inside "word".
			//Then find the code of each letter.
			//Then print the output - number of leaves, order of letters, tree structure and the encoded text - according to the explanation in the exercise.

			break;
		case 2:
			cout << "enter n ";
			cin >> n;
			cout << "enter the letters ";
			cin >> letters;
			cout << "enter the encoded structure ";
			cin >> codeStructure;
			cout << "enter the encoded text ";
			cin >> text; 

			//input the number of leaves, the  order of letters, tree structure and the encoded text.
			//build the Huffman Tree according to the tree strcture. put the letters in the leaves according to the given order. 
			//Given the Huffman Tree and the encoded text, find the original text, and print it. 
			cout<<"The decoded string is : ";
			t->encode(letters, codeStructure, text);
			break;
		}
//reset the tree
		/*delete t;
		t = new huffmanTree();*/
	} while (choice != 3);
	return 0;
}
