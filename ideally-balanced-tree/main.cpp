#include "ideallyBalancedTree.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	cout << "������������ ������ �4 \"���������� ��������� ������. �������� ������\". ���������� ����\n";

	cout << "�������� ����� �������:\n1) ������� �������� ���������������� ������ �� n �����.\n" <<
		"2) ���������� ������ �� ������, �������� ��� ������ ������� �������.\n" <<
		"3) ���������� �������, �� ������� ��������� �������� ��������.\n" <<
		"4) ���������� ���������� ���� � ����� ��������� ��������� ������\n" <<
		"5) ������� ������, ���������� �������� �����������\n" <<
		"0) ��������� ������ ���������.\n\n";



	int choice1;
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 0) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 0);
	if (choice1 == 0) return 0;
	cout << "������� ���������� �����: ";
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
		cout << "�������������� ����������� ��������� ������:\n";

		tree->printHor(tree->getRoot());

		break;
	}
	case 3: {
		cout << "������� ������� ��������: ";
		char c;
		cin >> c;

		cout << "������� ���������� �������� ��������(������� � 0): ";
		Node node;
		tree->search(tree->getRoot(), c, node);
		cout << node.deep;
		break;
	}
	case 4: {

		cout << "���-�� ���� � ����� ��������� ��������� ������: ";
		int res = 0;
		tree->findNumbers(tree->getRoot()->left, res);
		cout << res;
		break;
	}
	case 5: {
		cout << "������������ ����������� ��������� ������:\n";
		tree->printVert(tree->getRoot());
		break;
	}

	case 0:
		return 0;
	}
	cout << "\n\n";

	main();
}