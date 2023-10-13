#pragma once
#ifndef BINTREE_H
#define BINTREE_H

#include "bin_file.h"

#include<string>
using namespace std;

struct BinTreeNode {
	char number[8];
	int address=-1;

	BinTreeNode* left=nullptr;
	BinTreeNode* right=nullptr;
};

class BinaryTree : public BinFile  {
private:
	BinTreeNode* root=nullptr;
public:
	BinTreeNode* insert(BinTreeNode* node, string number);
	BinTreeNode* insert(string number);

	void createFromFile();

	BinTreeNode* findByKey(BinTreeNode* node, string number);
	BinTreeNode* findByKey(string number);

	string minElement(BinTreeNode* node);

	BinTreeNode* deleteByKey(BinTreeNode* node,string number);
	BinTreeNode* deleteByKey( string number);

	void printHor(const std::string& prefix, BinTreeNode* node, bool isLeft);
	void printHor();
};

#endif // !BINTREE_H
