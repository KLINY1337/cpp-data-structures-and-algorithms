#pragma once
#ifndef BALANCEDTREE_H
#define BALANCEDTREE_H

#include "bin_file.h"
using namespace std;

struct AVLNode{
	char number[8];
	int address=-1;

	
	AVLNode* left=nullptr;
	AVLNode* right=nullptr;
};

class AVLTree : public BinFile {
private:
	AVLNode* root = nullptr;
	
public:
	int rotationsAmount = 0;

	void createFromFile();

	AVLNode* insert(AVLNode* node, string number);
	AVLNode* insert(string number);

	AVLNode* balanceTree(AVLNode* node);
	AVLNode* balance(AVLNode* node);

	int heightDifference(AVLNode* node);
	int getHeight(AVLNode* node);

	AVLNode* rrRotation(AVLNode* parent);
	AVLNode* llRotation(AVLNode* parent);
	AVLNode* lrRotation(AVLNode* parent);
	AVLNode* rlRotation(AVLNode* parent);

	AVLNode* findByKey(AVLNode* node, string number);
	AVLNode* findByKey(string number);

	AVLNode* deleteByKey(AVLNode* node, string number);
	AVLNode* deleteByKey(string number);
	string minElement(AVLNode* node);

	void printHor(const std::string& prefix, AVLNode* node, bool isLeft);
	void printHor();

};
#endif