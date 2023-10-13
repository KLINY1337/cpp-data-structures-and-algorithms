#include "functions_bin.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Функция записи в файл
void fileInput(string file_name, string data) {
	ofstream fout;
	fout.open(file_name);

	if (fout.is_open()) {
		if (fout.good()) fout << data;
	}

	if (fout.good()) fout.close();
}
//Функция чтения файла
string fileOutput(string file_name) {
	ifstream fin;
	fin.open(file_name);
	char chr;
	string res = "";
	if (fin.is_open()) {
		while (fin.get(chr) && fin.good()) {
			res += chr;
		}
	}

	if (fin.eof())
		fin.close();

	return res;
}

//Функция дозаписи в конец файла
void fileAppend(string file_name, string data) {
	ofstream fout;
	fout.open(file_name, ios::app | ios::binary);

	if (fout.is_open()) {
		if (fout.good())
			fout << "\n" << data;
	}

	if (fout.good()) fout.close();
}

//Функция конвертации текстового файла в бинарный
void textToBin(string file_name_txt, string file_name_bin) {
	fstream fin = fstream(file_name_txt, ios::in);
	fstream fout = fstream(file_name_bin, ios::binary | ios::out);
	if (fin.is_open() && fout.is_open()) {

		fout << fin.rdbuf();

		if (fin.eof())
			fin.close();
		if (fout.fail() != ios::failbit)
			fout.close();
	}
}
//Функция вывода содержимого бинарного файла
void fileOutputBin(string file_name) {
	fstream fin(file_name, ios::binary | ios::in);

	if (fin.is_open()) cout << fin.rdbuf();


	if (fin.eof())
		fin.close();
}
//Функция получения записи по ее индексу
string fileGet(string file_name, string index) {
	ifstream fin(file_name, ios::in | ios::binary);
	string line = "";
	string str = "";
	if (fin.is_open()) {
		ifstream fin2(file_name, ios::in | ios::binary);
		while (fin2) {
			str += fin2.get();
		}
		fin2.close();

		if (str.find(index)!=-1) {
			fin.seekg(str.find(index)*sizeof(char));
			getline(fin, line);
		}
	}
	if (fin.fail() != ios::failbit)
		fin.close();
	return line;
}
//Функция удаления записи по ее индексу
void fileDelete(string file_name, string line) {
	string str = fileOutput(file_name);
	string strToCopy = "";
	for (int i = str.rfind("\n") + 1; i < str.length(); i++) {
		strToCopy += str[i];
	}
	int pos = str.find(line);

	for (int i = pos; i < pos+strToCopy.length(); i++) {
		str[i] = strToCopy[i-pos];
	}

	str = str.erase(str.rfind("\n"), strToCopy.length());
	fileInput(file_name, str);
}
//Функция тестирования операций с бинарным файлом
void testBinF() {
	textToBin("data.txt", "databin.bin");
	fileOutputBin("databin.bin");
	cout << "\n\n\n";
	cout << fileGet("databin.bin", "A131BC");
	cout << "\n\n\n";
	fileDelete("databin.bin", "A131BC TOY R DURKIN VS 28.08.2003\n");
	fileAppend("databin.bin", "U156ZJ CSO R OVFNQS CN 13.80.5713");
	fileOutputBin("databin.bin");
}