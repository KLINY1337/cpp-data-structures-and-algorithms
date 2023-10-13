#pragma once
#ifndef BIN_TREE
#define BIN_TREE

#include <iostream>
#include <vector>
using namespace std;

struct Node {
	char value;
	Node* left=nullptr;
	Node* right=nullptr;
	
	int deep = 0;
};

class Tree
{
private:
	Node** nodes;
	int amount = 0;

public:
	Tree( int n);
	Node* getRoot();
	void insertItem(int indexStart, int indexEl, int indexLeft, int indexRight, int deep);
	void printHor(const std::string& prefix, Node* node, bool isLeft);
	void printHor(Node* node);
	void search(Node* root, char key, Node& found);
	void pasteValues(char* arr);
	void findNumbers(Node* root, int& res);

	void printVert(Node* p);
	void printRow(const Node* p, const int height, int depth);
	void getLine(const Node* root, int depth, vector<char>& vals);
	int getHeight();
};





#endif