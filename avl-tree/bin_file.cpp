#include "bin_file.h"
#include <fstream>
#include <sstream>
#include <iostream>

//Метод создания бинарного файла
void BinFile::createBinFile(string fileTxt, string fileBin){
	this->fileBin = fileBin;

	fstream fin(fileTxt, ios::in | ios::binary);
	fstream fout(fileBin, ios::out | ios::binary);

	string s="";
	if (fin.is_open()) {
		while (getline(fin, s)) {
			if (s[s.length()-1]=='\r') s.erase(s.end()-1);
			this->nodesAmount++;
			stringstream ss(ios::in | ios::out);
			ss << s;
			Node node;
			ss >> node.number;
			ss >> node.surname;
			ss >> node.name;
			ss >> node.father;
			if (fout.is_open()) {
				fout.write((char*)&node, sizeof(Node));
			}
		}

		fin.close();
		fout.close();
	}
}

//Метод поиска записи по ключу
Node BinFile::printByKey(string key){
	fstream fin(fileBin, ios::in | ios::binary);

	Node node;

	if (fin.is_open()) {
		while (fin.read((char*)&node, sizeof(Node))) {

			if (string(node.number) == key) return node;
		}
		fin.close();
	}
}

//Метод поиска записи по адресу
Node BinFile::printByAddress(int address){
	fstream fin(fileBin, ios::in | ios::binary);

	Node node;

	if (fin.is_open()) {
		fin.seekg(address * sizeof(Node));
		fin.read((char*)&node, sizeof(Node));
		fin.close();
	}

	return node;
}

//Метод получения адреса записи по ключу
int BinFile::getAddressByKey(string key) {
	fstream fin(fileBin, ios::in | ios::binary);
	int result = -1;
	Node node;
	if (fin.is_open()) {
		while (fin.read((char*)&node, sizeof(Node))) {
			result++;
			if (string(node.number) == key) return result;
		}
		fin.close();
	}
	return -1;
}

//Метод добавления записи в файл
void BinFile::pasteNode(Node* node) {
	fstream fout(fileBin, ios::app | ios::binary);

	if (fout.is_open()) {
		fout.write((char*)node, sizeof(Node));
		fout.close();
	}
}

//int main() {
//	BinFile file;
//	file.createBinFile("test.txt", "test.bin");
//	Node node=file.printByKey("1234567");
//	//cout << string(node.number) << " " << string(node.surname);
//	file.printByAddress(1);
//}