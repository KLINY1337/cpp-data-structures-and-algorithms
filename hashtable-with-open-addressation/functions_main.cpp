#include "functions_bin.h"
#include "hash_table.h"
#include "functions_main.h"

#include <sstream>

//������� ������� �������� � ���-������� �� �����
void pasteEl(string file_name, HashTable& table, string index) {
	string str = fileGet(file_name, index);
	stringstream ss(ios::in | ios::out);

	ss << str;

	Node node;
	ss >> node.number;
	ss >> node.model;
	ss >> node.color;
	ss >> node.surname;
	ss >> node.name;
	ss >> node.date;

	table.pasteKey(node);

}

//������� �������� �������� �� ����� � ���-�������
void deleteEl(string file_name, HashTable& table, string line) {
	fileDelete(file_name, line);

	stringstream ss(ios::in | ios::out);

	ss << line;

	Node node;
	ss >> node.number;
	ss >> node.model;
	ss >> node.color;
	ss >> node.surname;
	ss >> node.name;
	ss >> node.date;

	table.deleteKey(node);
}

//������� ������ �������� � ���-������� � �������� �����
string findEl(string file_name, HashTable& table, Node node) {
	int pos=table.findKey(node);

	string index = table.table[pos].number;

	return fileGet(file_name, index);
}

