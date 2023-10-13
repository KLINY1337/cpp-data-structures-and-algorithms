#include "ideallyBalancedTree.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	cout << "Лабораторная работа №4 \"Нелинейные структуры данных. Бинарное дерево\". Черномуров Семён\n";

	cout << "Выберите номер задания:\n1) Создать идеально сбалансированное дерево из n узлов.\n" <<
		"2) Отобразить дерево на экране, повернув его против часовой стрелки.\n" <<
		"3) Определить уровень, на котором находится заданное значение.\n" <<
		"4) Определить количество цифр в левом поддереве исходного дерева\n" <<
		"5) Вывести дерево, располагая элементы вертикально\n" <<
		"0) Завершить работу программы.\n\n";



	int choice1;
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 0);
	if (choice1 == 0) return 0;
	cout << "Введите количество узлов: ";
	int amount;
	cin >> amount;
	Tree* tree = new Tree(amount);
	char arr[16] = { '0','2','A','B','3','4','C','D','5','6','E','F','7','8','G','H' };
	tree->pasteValues(arr);
	system("cls");
	switch (choice1)
	{
	case 1: {
		break;
	}
	case 2: {
		cout << "Горизонтальное отображение бинарного дерева:\n";

		tree->printHor(tree->getRoot());

		break;
	}
	case 3: {
		cout << "Введите искомое значение: ";
		char c;
		cin >> c;

		cout << "Уровень нахождения искомого значения(начиная с 0): ";
		Node node;
		tree->search(tree->getRoot(), c, node);
		cout << node.deep;
		break;
	}
	case 4: {

		cout << "Кол-во цифр в левом поддереве исходного дерева: ";
		int res = 0;
		tree->findNumbers(tree->getRoot()->left, res);
		cout << res;
		break;
	}
	case 5: {
		cout << "Вертикальное отображение бинарного дерева:\n";
		tree->printVert(tree->getRoot());
		break;
	}

	case 0:
		return 0;
	}
	cout << "\n\n";

	main();
}