#include "ideallyBalancedTree.h"
#include<string>
#include<vector>
#include <iomanip>
using namespace std;

//Метод конструктора дерева
Tree::Tree(int n) {
	this->nodes = new Node*[n];
	this->amount = n;


	for (int i = 0; i < amount; i++) {
		nodes[i] = new Node();
	}

	insertItem(0, 1, 1, 2, 0);

}

//Метод построения струтуры дерева
void Tree::insertItem(int indexStart, int indexEl, int indexLeft, int indexRight, int deep) {

	for (int i = indexStart; i < indexEl; i++) {
		nodes[i]->deep = deep;
		if (i + indexLeft < amount) {
			nodes[i]->left = nodes[i + indexLeft]; nodes[i]->left->deep = deep + 1;
		}
		else {
			if (i + indexLeft > amount) continue;
			if (i + indexLeft == amount) return;
		}

		if (i + indexRight < amount) {nodes[i]->right = nodes[i + indexRight]; nodes[i]->right->deep = deep + 1;}
		else {
			if (i + indexRight > amount) continue;
			if (i + indexRight == amount) return;
		}

	}

	insertItem(indexStart + indexLeft, indexEl + indexRight, indexLeft * 2, indexRight * 2, deep+1);
}

//Метод получения корневой записи дерева
Node* Tree::getRoot() {
	return nodes[0];
}

//Метод вывода дерева по горизонтали
void Tree::printHor(const std::string& prefix, Node* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "|--" : "L--");

		// print the value of the node
		std::cout << node->value << std::endl;

		// enter the next tree level - left and right branch
		printHor(prefix + (isLeft ? "|   " : "    "), node->left, true);
		printHor(prefix + (isLeft ? "|   " : "    "), node->right, false);
	}
}

//Перегрузка метода вывода дерева на экран по горизонтали
void Tree::printHor(Node* node)
{
	printHor("", node, false);
}

//Метод заполнения записей дерева значениями
void Tree::pasteValues(char* arr) {
	for (int i = 0; i < amount; i++) {
		nodes[i]->value = arr[i];
	}


}

//Метод поиска уровня записи с заданным значением
void Tree::search(Node* root, char key, Node& found) {
	if (root) {
		if (root->value == key) found=*root;
		search(root->left, key, found);
		
		search(root->right,key, found);
	}
}

//Метод подсчета количества цифр в левом поддереве
void Tree::findNumbers(Node* root, int& res) {
	if (root) {
		if (root->value >= '0' && root->value <= '9') res++;
		findNumbers(root->left, res);
		findNumbers(root->right, res);
	}
}

//Метод получения высоты дерева
int Tree::getHeight() {
	int max = -1;
	for (int i = 0; i < amount; i++) {
		if (nodes[i]->deep > max) max = nodes[i]->deep;
	}
	return max;
}

//Метод вертикального вывода дерева на экран
void Tree::printVert(Node* p)
{
	int height =  getHeight();
	for (int i = 0; i < height; i++) {
		printRow(p, height, i);
	}
}
//Метод вывода строки-уровня для вертикального вывода дерева на экран
void Tree::printRow(const Node* p, const int height, int depth)
{
	vector<char> vec;
	getLine(p, depth, vec);
	cout << setw((height - depth) * 2); // scale setw with depth
	bool toggle = true; // start with left
	if (vec.size() > 1) {
		for (char v : vec) {
			if (v != '_') {
				if (toggle)
					cout << "/" << "   ";
				else
					cout << "\\" << "   ";
			}
			toggle = !toggle;
		}
		cout << endl;
		cout << setw((height - depth) * 2);
	}
	for (char v : vec) {
		if (v != '_')
			cout << v << "   ";
	}
	cout << endl;
}
//Метод формирования строки для вертикального вывода дерева на экран
void Tree::getLine(const Node * root, int depth, vector<char>&vals)
{
	if (depth <= 0 && root != nullptr) {
		vals.push_back(root->value);
		return;
	}
	if (root->left != nullptr)
		getLine(root->left, depth - 1, vals);
	else if (depth - 1 <= 0)
		vals.push_back('_');
	if (root->right != nullptr)
		getLine(root->right, depth - 1, vals);
	else if (depth - 1 <= 0)
		vals.push_back('_');
}