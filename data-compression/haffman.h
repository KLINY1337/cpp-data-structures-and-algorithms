#pragma once
#ifndef HAFFMAN_H
#define HAFFMAN_H

#include <string>
#include <queue>
#include <unordered_map>
#include <functional>

class Haffman {
private:
	
	struct Node
	{
		char symbol;
		int amount;
		Node* left;
		Node* right;
	};

	Node* root;

	std::unordered_map<char, std::string> haffmanCode;

	void compress(Node* root, std::string code);
	void decode(Node* root, int& index);
	
public:
	Haffman(std::string data);
	void decompress();
	std::string compressedData = "";
};

#endif