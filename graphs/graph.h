#pragma once
#ifndef GRAPH_H
#define GRAPH_H


class Graph
{
public:
	Graph(int amount);
	void initialize();
	void print();
	void createMatrixOfReach();
	bool checkConnectivity();;
	void printMatrixOfReach();
	void findMinimalPath(int beginIndex, int endIndex);
	void printPath();
	void printMinimalWeight(int n); // endIndex

private:
	int amount = 0;
	int** matrixSmezh;
	int** matrixReach;
	int* path;
	int* minPath;
	int k;
};


#endif