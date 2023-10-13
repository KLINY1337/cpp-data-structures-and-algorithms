#include "haffman.h"
#include <windows.h>
#include <iostream>
using namespace std;

//Конструктор класса Haffman
Haffman::Haffman(string data)
{
	unordered_map<char, int> amount;
	for (int i = 0; i < data.size(); i++) {
		amount[data[i]]++;
	}

	auto comparator = [](Node* a, Node* b)->bool {return a->amount > b->amount; };
	priority_queue < Node*, vector<Node*>, decltype(comparator)> probabilities(comparator);
	
	

	for (auto pair : amount) {
		Node* node = new Node;
		node->symbol = pair.first;
		node->amount = pair.second;
		node->left = nullptr;
		node->right = nullptr;
		probabilities.push(node);
	}

	

	while (probabilities.size() != 1)
	{
		Node* left = probabilities.top();
		probabilities.pop();

		Node* right = probabilities.top();
		probabilities.pop();

		int sum = left->amount + right->amount;
		Node* node = new Node;
		node->symbol = '\0';
		node->amount = sum;
		node->left = left;
		node->right = right;
		probabilities.push(node);
	}


	this->root = probabilities.top();

	compress(root, "");

	for (int i = 0; i < data.size(); i++) // получить закодированную строку
		compressedData += haffmanCode[data[i]];

}
// Метод создания кодов Хаффмана
void Haffman::compress(Node* root, string code) {
	if (root == nullptr) {
		return;
	}

	if (root->left == nullptr && root->right == nullptr) {
		haffmanCode[root->symbol] = code;
	}

	compress(root->left, code + "0");
	compress(root->right, code + "1");
}

// Метод декодирования кодов Хаффмана
void Haffman::decode(Node* root, int& index) {
	if (root == nullptr) {
		return;
	}

	if (root->left==nullptr && root->right==nullptr) {
		cout << root->symbol;
		return;
	}

	index++;

	if (compressedData[index] == '0') {
		decode(root->left, index);
	}
	else {
		decode(root->right, index);
	}
}

// Метод вызова метода декодирования кодов Хаффмана
void Haffman::decompress() {
	int index = -1;
	//cout << "\n" << compressedData.size() - 2;
	while (index < (int)compressedData.size() - 2) { // декодировать строку
		decode(root, index);
	}
}

//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	setlocale(0, "");
//
//	Haffman obj(data);
//	cout << obj.compressedData;
//	obj.decompress();
//	return 0;
//}
