#include "shannon-fano.h"
#include <algorithm>
#include <iostream>
#include <windows.h>
using namespace std;

// Метод получения кодов Шеннона-Фано
void ShannonFano::getCodes(vector<Node> probabilities, string code) {
	int separateIndex = separate(probabilities);
	//cout << separateIndex << "\n";
	vector<Node> left = {};
	vector<Node> right = {};


	for (int i = 0; i < separateIndex; i++) {
		left.push_back(probabilities[i]);
	}
	for (int i = separateIndex; i < probabilities.size(); i++) {
		right.push_back(probabilities[i]);
	}
	
	

	if (left.size() > 1) getCodes(left, code + "0");
	else {
		//cout << left[0].symbol << " " << code+"0"<<"\n";
		for (int i = 0; i < this->probabilities.size(); i++) {
			if (probabilities[i].symbol == left[0].symbol) {
				Code node;
				node.code = code + "0";
				node.symbol = left[0].symbol;
				this->codes.push_back(node);
				break;
			}
		}

	}
	if (right.size() > 1) getCodes(right, code+"1");
	else {
		//cout << right[0].symbol << " " << code+"1"<<"\n";
		for (int i = 0; i < this->probabilities.size(); i++) {
			if (probabilities[i].symbol == right[0].symbol) {
				Code node;
				node.code = code + "1";
				node.symbol = right[0].symbol;
				this->codes.push_back(node);
				break;
			}
		}
	}
}

// Метод выбора оптимального места разделения массива вероятностей
int ShannonFano::separate(vector<Node> probabilities) {
	int position = 1;
	float minimalSum = 1.0;
	int result=1;
	while (position < probabilities.size() - 2) {
		float sum1 = 0, sum2 = 0;
		for (int i = 0; i < position; i++) {
			sum1 += probabilities[i].probability;
		}
		for (int i = position; i < probabilities.size(); i++) {
			sum2 += probabilities[i].probability;
		}
		if (abs(sum2 - sum1) < minimalSum) {
			minimalSum = abs(sum2 - sum1);
			result = position;
		}
		position++;
	}
	return result;
}


// Метод конструктора класса ShannonFano
ShannonFano::ShannonFano(const string data) {
	this->data = data;
	this->probabilities= getProbabilities(data);
	getCodes(probabilities,"");

	for (int i = 0; i < data.size(); i++) {
		string code;
		for (int j = 0; j < codes.size(); j++) {
			if (codes[j].symbol == data[i]) {
				code = codes[j].code;
				break;
			}
		}
		compressedData += code;
	}
}

// Метод получения вероятностей встречи символов алфавите в тексте
vector<ShannonFano::Node> ShannonFano::getProbabilities(const string data) {
	for (int i = 0; i < data.size(); i++) {
		long counter = count(data.begin(), data.end(), data[i]);
		int k = 0;
		for (int j = 0; j < probabilities.size(); j++) {
			if (probabilities[j].symbol == data[i]) break;
			else k++;
		}
		if (k == probabilities.size()) {
			Node node;
			node.symbol = data[i];
			node.probability = counter * 1.0 / data.size();
			probabilities.push_back(node);
		}
	}
	sort(probabilities.begin(), probabilities.end(), [](Node a, Node b) {return a.probability > b.probability; });
	return this->probabilities;
}

// Метод декодирования кодов Шеннона-Фано
void ShannonFano::decompress() {
	string buffer = "";
	for (int i = 0; i < compressedData.size(); i++) {
		buffer += compressedData[i];
		for (int j = 0; j < codes.size(); j++) {
			if (buffer == codes[j].code) {
				cout << codes[j].symbol;
				buffer = "";
				break;
			}
		}
	}
}

//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	setlocale(0, "");
//	//const string data = "ABCABCDDEHFGY";

//	ShannonFano obj(data);
//	cout << obj.compressedData<<"\n";
//	obj.decompress();
//}