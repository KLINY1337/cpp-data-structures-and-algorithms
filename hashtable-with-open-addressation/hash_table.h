#pragma once

#include <string>
using namespace std;

struct Node {
	string number;
	string model;
	string color;
	string surname;
	string name;
	string date;
};

class HashTable {
private:
	int length=0;
	int totalNodes;
	

public:
	Node* table;
	HashTable(int length);

	long long hashCode(Node node);
	bool pasteKey(Node node);
	bool deleteKey(Node node);
	int findKey(Node node);
	void rehashTable();

	void outputTable();
};

void testHeshT();