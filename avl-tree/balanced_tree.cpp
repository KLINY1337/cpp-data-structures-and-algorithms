#include "balanced_tree.h"
#include <iostream>

//Метод вставки записи в АВЛ-дерево
AVLNode* AVLTree::insert(AVLNode* node, string number) {
	if (node == nullptr) {
		node = new AVLNode();
		number.copy(node->number, 7);
		node->address = getAddressByKey(number);
		if (root == nullptr) root = node;
		return node;
	}

	if (atoi(number.c_str()) < atoi(node->number))
		node->left = insert(node->left, number);
	else
		node->right = insert(node->right, number);
	return node;
}

//Перегрузка метода вставки записи в АВЛ дерево
AVLNode* AVLTree::insert(string number) {
	AVLNode* node = insert(root, number);
	root = balanceTree(root);
	return node;
}

//Метод вызова балансировки дерева
AVLNode* AVLTree::balanceTree(AVLNode* node) {
	if (node == nullptr) return node;
	node->left = balanceTree(node->left);
	node->right = balanceTree(node->right);
	node = balance(node);
	return node;
}

//Метод балансировки дерева
AVLNode* AVLTree::balance(AVLNode* node) {
	int balanceFactor = heightDifference(node);

	if (balanceFactor > 1) {
		if (heightDifference(node->left) > 0) {
			node = llRotation(node);
		}
		else {
			node = lrRotation(node);
		}
	}
	else if (balanceFactor < -1) {
		if (heightDifference(node->right) > 0) {
			node = rlRotation(node);
		}
		else {
			node = rrRotation(node);
		}
	}
	return node;
}

//Метод малого правого поворота
AVLNode* AVLTree::rrRotation(AVLNode* parent) {
	rotationsAmount++;
	AVLNode* node;
	node = parent->right;
	parent->right = node->left;
	node->left = parent;
	return node;
}
//Метод малого левого поворота
AVLNode* AVLTree::llRotation(AVLNode* parent) {
	rotationsAmount++;
	AVLNode* node;
	node = parent->left;
	parent->left = node->right;
	node->right = parent;
	return node;
}
//Метод левого поворота
AVLNode* AVLTree::lrRotation(AVLNode* parent) {
	rotationsAmount++;
	AVLNode* node;
	node = parent->left;
	parent->left = rrRotation(node);
	return llRotation(parent);
}
//Метод правого поворота
AVLNode* AVLTree::rlRotation(AVLNode* parent) {
	rotationsAmount++;
	AVLNode* node;
	node = parent->right;
	parent->right = llRotation(node);
	return rrRotation(parent);
}
//Метод вычисления разницы высот левого и правого поддерева
int AVLTree::heightDifference(AVLNode* node) {
	int leftHeight = getHeight(node->left);
	int rightHeight = getHeight(node->right);

	int balanceFactor = getHeight(node->left) - getHeight(node->right);
	return balanceFactor;
	/*return getHeight(node->left) - getHeight(node->right);*/
}

//Метод получения высоты дерева
int AVLTree::getHeight(AVLNode* node){
	if (node != nullptr) {
		int leftHeight = getHeight(node->left);
		int rightHeight = getHeight(node->right);

		return max(leftHeight, rightHeight) + 1;
	}
	return 0;
}
//Метод создания АВЛ-дерева из бинарного файла
void AVLTree::createFromFile() {
	Node node;
	for (long long i = 0; i < nodesAmount; i++) {
		node = printByAddress(i);
		insert(node.number);
		//if (i % 1000 == 0) cout << i;
	}
}
//Метод поиска записи по ключу в АВЛ-дереве
AVLNode* AVLTree::findByKey(AVLNode* node, string number) {

	if (node == nullptr || atoi(node->number) == atoi(number.c_str())) return node;
	if (atoi(node->number) < atoi(number.c_str())) return findByKey(node->right, number);
	if (atoi(node->number) > atoi(number.c_str())) return findByKey(node->left, number);
}
//Перегрузка метода поиска записи по ключу в АВЛ-дереве
AVLNode* AVLTree::findByKey(string number) {
	return findByKey(root, number);
}

//Метод удаления записи из АВЛ-дерева по ключу
AVLNode* AVLTree::deleteByKey(AVLNode* node, string number){
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
//Перегрузка метода удаления записи из АВЛ-дерева по ключу
AVLNode* AVLTree::deleteByKey(string number) {
	AVLNode* node = deleteByKey(root, number);
	root = balanceTree(root);
	return node;
}
//Метод поиска минимального элемента в дереве
string AVLTree::minElement(AVLNode* node) {
	if (node->left == nullptr) {
		return string(node->number);

	}
	return minElement(node->left);
}

//Метод вывода дерева на экран по горизонтали
void AVLTree::printHor(const std::string& prefix, AVLNode* node, bool isLeft) {
	if (node != nullptr)
	{
		cout << prefix;

		cout << (isLeft ? "|--" : "L--");

		// print the value of the node
		cout << node->address << endl;

		// enter the next tree level - left and right branch
		printHor(prefix + (isLeft ? "|   " : "    "), node->left, true);
		printHor(prefix + (isLeft ? "|   " : "    "), node->right, false);
	}
}

//Перегрузка метода вывода дерева на экран по горизонтали
void AVLTree::printHor() {
	printHor("", root, false);
}

//int main() {
//	AVLTree tree;
//	tree.createBinFile("test.txt", "test.bin");
//	tree.createFromFile();
//
//
//	tree.printHor();
//	cout << "\n\n\n";
//	tree.deleteByKey("3");
//	tree.printHor();
//}