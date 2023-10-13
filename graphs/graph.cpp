#include "graph.h"

#include <iostream>
#include <iomanip>
using namespace std;

//конструктор графа
Graph::Graph(int amount) {
	this->amount = amount;
	matrixSmezh = new int* [amount];
	for (int i = 0; i < amount; i++)
		matrixSmezh[i] = new int[amount];

	matrixReach = new int* [amount];
	for (int i = 0; i < amount; i++)
		matrixReach[i] = new int[amount];

	this->path = new int[amount];
	memset(path, 0, amount*sizeof(int));

	this->minPath = new int[amount]; //минимальное рассто€ние
}

//метод ввода графа с клавиатуры
void Graph::initialize() {
	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < amount; j++) {
			cin >> matrixSmezh[i][j];
		}
	}
}

//метод вывода графа на экран
void Graph::print() {
	cout << "   ";
	for (int i = 0; i < amount; i++)
		cout << setw(3) << i + 1;
	cout << "\n";
	cout << "___";
	for (int i = 0; i < amount; i++) {
		cout << "___";
	}
	cout << "\n";
	for (int i = 0; i < amount; i++) {
		cout << setw(2) << right << i + 1;
		cout << "|";
		for (int j = 0; j < amount; j++) {
			cout << setw(3) << right << matrixSmezh[i][j];
		}
		cout << "\n";
	}
}
//метод вывода матрицы достижимости на экран (вспомогательный)
void Graph::printMatrixOfReach() {
	cout << "   ";
	for (int i = 0; i < amount; i++)
		cout << setw(3) << i + 1;
	cout << "\n";
	cout << "___";
	for (int i = 0; i < amount; i++) {
		cout << "___";
	}
	cout << "\n";
	for (int i = 0; i < amount; i++) {
		cout << setw(2) << right << i + 1;
		cout << "|";
		for (int j = 0; j < amount; j++) {
			cout << setw(3) << right << matrixReach[i][j];
		}
		cout << "\n";
	}
}

//метод создани€ матрицы достижимости
void Graph::createMatrixOfReach() {
	int** matrixSmezh2 = new int* [amount];
	for (int i = 0; i < amount; i++)
		matrixSmezh2[i] = new int[amount];
	

	for (int i = 0; i < amount; i++)
		for (int j = 0; j < amount; j++)
			if (matrixSmezh[i][j] <=0) matrixSmezh2[i][j] = 0;
			else matrixSmezh2[i][j] = 1;

	for (int i = 0; i < amount; i++)
		for (int j = 0; j < amount; j++)
			matrixReach[i][j] = matrixSmezh2[i][j];
			

	for (int k = 0; k < amount; k++)
		for (int i = 0; i < amount; i++)
			for (int j = 0; j < amount; j++)
				matrixReach[i][j] = (matrixReach[i][j] | (matrixReach[k][j] & matrixReach[i][k]));
}

//метод проверки св€зности графа
bool Graph::checkConnectivity() {
	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < amount; j++) {
			if (matrixReach[i][j] == 0) return false;
		}
	}
	return true;
}

//метод нахождени€ минимального пути методом ƒейкстры
void Graph::findMinimalPath(int beginIndex, int endIndex) {
	beginIndex--;
	endIndex--;

	
	int* visited = new int[amount]; //посещенные вершины

	//»нициализаци€ вершин и рассто€ний
	for (int i = 0; i < amount; i++)
	{
		minPath[i] = 10000;
		visited[i] = 1; // 1 - не посещена
	}

	int minIndex, minWeight;
	minPath[beginIndex] = 0;

	// Ўаг алгоритма
	do {
		minIndex = 10000;
		minWeight = 10000;
		for (int i = 0; i < amount; i++)
		{ // ≈сли вершину ещЄ не обошли и вес меньше минимального
			if (visited[i] == 1 && minPath[i] < minWeight)
			{
				minWeight = minPath[i];
				minIndex = i;
			}
		}
		// ƒобавл€ем найденный минимальный вес
		// к текущему весу вершины
		// и сравниваем с текущим минимальным весом вершины
		if (minIndex != 10000)
		{
			for (int i = 0; i < amount; i++)
			{
				if (matrixSmezh[minIndex][i] > 0)
				{
					int temp = minWeight + matrixSmezh[minIndex][i];
					if (temp < minPath[i])
					{
						minPath[i] = temp;
					}
				}
			}
			visited[minIndex] = 0; // вершина посещена
		}
	} while (minIndex < 10000);



	// ¬осстановление пути
	
	path[0] = endIndex + 1; // первый элемент - конечна€ вершина (все перевернуто)
	int k = 1; // индекс предыдущей вершины (0+1)
	int weight = minPath[endIndex]; // вес конечной вершины

	while (endIndex != beginIndex) // пока не дошли до начальной вершины
	{
		for (int i = 0; i < amount; i++) // просматриваем все вершины
			if (matrixSmezh[i][endIndex] != 0)   // если св€зь есть
			{
				int temp = weight - matrixSmezh[i][endIndex]; // определ€ем вес пути из предыдущей вершины
				if (temp == minPath[i]) // если вес совпал с рассчитанным
				{                 // значит из этой вершины и был переход
					weight = temp; // сохран€ем новый вес
					endIndex = i;       // сохран€ем предыдущую вершину
					path[k] = i + 1; // и записываем ее в массив
					k++;
				}
			}
	}
	this->k = k - 1;
		
}

//метод вывода минимального пути на экран
void Graph::printPath() {
	for (int i = k; i >= 0; i--) {
		cout << path[i] << " ";
	}
}

//метод вывода веса минимального пути на экран
void Graph::printMinimalWeight(int n) {
	cout << minPath[n-1];

}

//int main() {
//	Graph g(5);
//	g.initialize();
//	g.createMatrixOfReach();
//	g.print();
//	g.printMatrixOfReach();
//	cout << g.checkConnectivity()<<"\n\n";
//	//сделана перва€ функци€ из варианта`
//	g.findMinimalPath(1,4);
//	g.printPath();
//	cout << "\n\n";
//	g.printMinimalWeight(4);
//}