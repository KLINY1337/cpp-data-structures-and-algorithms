#include "graph.h"

#include <iostream>
#include <iomanip>
using namespace std;

//����������� �����
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

	this->minPath = new int[amount]; //����������� ����������
}

//����� ����� ����� � ����������
void Graph::initialize() {
	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < amount; j++) {
			cin >> matrixSmezh[i][j];
		}
	}
}

//����� ������ ����� �� �����
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
//����� ������ ������� ������������ �� ����� (���������������)
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

//����� �������� ������� ������������
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

//����� �������� ��������� �����
bool Graph::checkConnectivity() {
	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < amount; j++) {
			if (matrixReach[i][j] == 0) return false;
		}
	}
	return true;
}

//����� ���������� ������������ ���� ������� ��������
void Graph::findMinimalPath(int beginIndex, int endIndex) {
	beginIndex--;
	endIndex--;

	
	int* visited = new int[amount]; //���������� �������

	//������������� ������ � ����������
	for (int i = 0; i < amount; i++)
	{
		minPath[i] = 10000;
		visited[i] = 1; // 1 - �� ��������
	}

	int minIndex, minWeight;
	minPath[beginIndex] = 0;

	// ��� ���������
	do {
		minIndex = 10000;
		minWeight = 10000;
		for (int i = 0; i < amount; i++)
		{ // ���� ������� ��� �� ������ � ��� ������ ������������
			if (visited[i] == 1 && minPath[i] < minWeight)
			{
				minWeight = minPath[i];
				minIndex = i;
			}
		}
		// ��������� ��������� ����������� ���
		// � �������� ���� �������
		// � ���������� � ������� ����������� ����� �������
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
			visited[minIndex] = 0; // ������� ��������
		}
	} while (minIndex < 10000);



	// �������������� ����
	
	path[0] = endIndex + 1; // ������ ������� - �������� ������� (��� �����������)
	int k = 1; // ������ ���������� ������� (0+1)
	int weight = minPath[endIndex]; // ��� �������� �������

	while (endIndex != beginIndex) // ���� �� ����� �� ��������� �������
	{
		for (int i = 0; i < amount; i++) // ������������� ��� �������
			if (matrixSmezh[i][endIndex] != 0)   // ���� ����� ����
			{
				int temp = weight - matrixSmezh[i][endIndex]; // ���������� ��� ���� �� ���������� �������
				if (temp == minPath[i]) // ���� ��� ������ � ������������
				{                 // ������ �� ���� ������� � ��� �������
					weight = temp; // ��������� ����� ���
					endIndex = i;       // ��������� ���������� �������
					path[k] = i + 1; // � ���������� �� � ������
					k++;
				}
			}
	}
	this->k = k - 1;
		
}

//����� ������ ������������ ���� �� �����
void Graph::printPath() {
	for (int i = k; i >= 0; i--) {
		cout << path[i] << " ";
	}
}

//����� ������ ���� ������������ ���� �� �����
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
//	//������� ������ ������� �� ��������`
//	g.findMinimalPath(1,4);
//	g.printPath();
//	cout << "\n\n";
//	g.printMinimalWeight(4);
//}