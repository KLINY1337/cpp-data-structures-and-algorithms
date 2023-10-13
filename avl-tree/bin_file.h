#pragma once
#ifndef BINF_H
#define BINF_H

#include<string>
using namespace std;

struct Node {
	char number[8];
	char surname[8];
	char name[8];
	char father[8];
};

class BinFile {
protected:
	string fileBin;
	

public:
	int nodesAmount = 0;
	void createBinFile(string fileTxt, string fileBin);
	Node printByKey(string key);
	Node printByAddress(int address);
	int getAddressByKey(string key);
	void pasteNode(Node* node);
};

#endif