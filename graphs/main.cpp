#include "graph.h"
#include <iostream>
#include <chrono>
using namespace std;

Graph* graph;

int main() {
	setlocale(LC_ALL, "");

	cout << "Лабораторная работа №6 \"Основные алгоритмы работы с графами\". Черномуров Семён\n";

	cout << "Выберите номер задания:\n1) Ввести граф с клавиатуры.\n" <<
		"2) Вывести граф на экран.\n" <<
		"3) Определить, является ли граф связным.\n" <<
		"4) Найти кратчайший путь (алгоритм Дейкстра).\n" <<
		"0) Завершить работу программы\n\n";



	int choice1;
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 0);

	system("cls");
	
	switch (choice1)
	{
	case 1: {
		cout << "Введите число вершин графа: ";
		int n;
		cin >> n;
		graph = new Graph(n);
		cout << "Введите матрицу смежности графа:\n";
		graph->initialize();
		cout << "Граф успешно создан.\n\n";
		break;
	}
	case 2: {
		cout << "Матрица смежности графа:\n";
		graph->print();
		break;
	}
	case 3: {
		cout << "Проверка связности графа: граф ";
		if (graph->checkConnectivity()) cout << "связный.\n\n";
		else cout << "несвязный.\n\n";
		graph->createMatrixOfReach();	
		graph->printMatrixOfReach();
		break;
	}
	case 4: {
		cout << "Введите номер вершин начала и конца: ";
		int begin, end;
		cin >> begin >> end;
		graph->findMinimalPath(begin, end);
		cout << "Минимальный вес пути между вершинами: ";
		graph->printMinimalWeight(end);
		cout << "\nЭтот путь: ";
		graph->printPath();
		cout << "\n\n";
		break;
	}
	
	case 0:
		return 0;
	}
	

	main();
}