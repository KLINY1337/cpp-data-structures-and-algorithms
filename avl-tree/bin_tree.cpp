#include "bin_tree.h"
#include <iostream>

//����� ������� ������ � ���
BinTreeNode* BinaryTree::insert(BinTreeNode* node, string number) {
	if (node == nullptr) {
		node = new BinTreeNode();
		number.copy(node->number, 7);
		node->address = getAddressByKey(number);
		if (root == nullptr) root = node;
		return node;
	}

	if (atoi(number.c_str()) < atoi(node->number))
		node->left=insert(node->left, number);
	else
		node->right=insert(node->right, number);
	return node;
}

//���������� ������ ������� ������ � ���
BinTreeNode* BinaryTree::insert(string number) {
	return insert(root, number);
}

//����� �������� ��� �� ��������� �����
void BinaryTree::createFromFile() {
	Node node;
	for (long long i = 0; i < nodesAmount; i++) {
		node = printByAddress(i);
		insert(node.number);
		//if (i % 1000 == 0) cout << i;
	}
}

//����� ������ ������ � ��� �� �����
BinTreeNode* BinaryTree::findByKey(BinTreeNode* node, string number) {
	

	if (node==nullptr || atoi(node->number) == atoi(number.c_str())) return node;
	if (atoi(node->number) < atoi(number.c_str())) return findByKey(node->right,number);
	if (atoi(node->number) > atoi(number.c_str())) return findByKey(node->left, number);
}

//���������� ������ ������ ������ � ��� �� �����
BinTreeNode* BinaryTree::findByKey(string number) {
	return findByKey(root, number);
}

//����� ������ ������������ �������� � ���
string BinaryTree::minElement(BinTreeNode* node) {
	if (node->left == nullptr) {
		return string(node->number);
		
	}
	return minElement(node->left);
}

//����� �������� ������ � ��� �� �����
BinTreeNode* BinaryTree::deleteByKey(BinTreeNode* node,string number) {
	if (node == nullptr) return nullptr;

	if (atoi(node->number) > atoi(number.c_str())) node->left = deleteByKey(node->left, number);
	else if (atoi(node->number) < atoi(number.c_str())) node->right = deleteByKey(node->right, number);
	else if (node->left != nullptr && node->right != nullptr) {
		minElement(node->right).copy(node->number, 7);
		node->right = deleteByKey(node->right, string(node->number));
	}
	else {
		if (node->left != nullptr) {
			node = node->left;
		}
		else if (node->right != nullptr) {
			node = node->right;
		}
		else {
			node = nullptr;
		}
	}
	return node;
}

//���������� ������ ���������� ������ � ��� �� �����
BinTreeNode* BinaryTree::deleteByKey(string number) {
	return deleteByKey(root, number);
}

//����� ������ ������ �� �����������
void BinaryTree::printHor(const std::string& prefix, BinTreeNode* node, bool isLeft) {
	if (node != nullptr)
	{
		cout << prefix;

		cout << (isLeft ? "|--" : "L--");

		cout << string(node->number) << endl;

		printHor(prefix + (isLeft ? "|   " : "    "), node->left, true);
		printHor(prefix + (isLeft ? "|   " : "    "), node->right, false);
	}
}

//���������� ������ ������ ������ �� ����� �� �����������
void BinaryTree::printHor() {
	printHor("", root, false);
}
