#include "graph.h"
#include <iostream>
#include <chrono>
using namespace std;

Graph* graph;

int main() {
	setlocale(LC_ALL, "");

	cout << "������������ ������ �6 \"�������� ��������� ������ � �������\". ���������� ����\n";

	cout << "�������� ����� �������:\n1) ������ ���� � ����������.\n" <<
		"2) ������� ���� �� �����.\n" <<
		"3) ����������, �������� �� ���� �������.\n" <<
		"4) ����� ���������� ���� (�������� ��������).\n" <<
		"0) ��������� ������ ���������\n\n";



	int choice1;
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 0) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 0);

	system("cls");
	
	switch (choice1)
	{
	case 1: {
		cout << "������� ����� ������ �����: ";
		int n;
		cin >> n;
		graph = new Graph(n);
		cout << "������� ������� ��������� �����:\n";
		graph->initialize();
		cout << "���� ������� ������.\n\n";
		break;
	}
	case 2: {
		cout << "������� ��������� �����:\n";
		graph->print();
		break;
	}
	case 3: {
		cout << "�������� ��������� �����: ���� ";
		if (graph->checkConnectivity()) cout << "�������.\n\n";
		else cout << "���������.\n\n";
		graph->createMatrixOfReach();	
		graph->printMatrixOfReach();
		break;
	}
	case 4: {
		cout << "������� ����� ������ ������ � �����: ";
		int begin, end;
		cin >> begin >> end;
		graph->findMinimalPath(begin, end);
		cout << "����������� ��� ���� ����� ���������: ";
		graph->printMinimalWeight(end);
		cout << "\n���� ����: ";
		graph->printPath();
		cout << "\n\n";
		break;
	}
	
	case 0:
		return 0;
	}
	

	main();
}