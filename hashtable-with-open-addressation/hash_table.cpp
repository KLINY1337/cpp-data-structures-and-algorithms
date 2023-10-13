#include "hash_table.h"

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <sstream>
#include "random"

//Метод конструктора хеш-таблицы
HashTable::HashTable(int length) {
	this->length = length;
	this->totalNodes = 0;
	this->table = new Node[length];

	Node clearNode;
	clearNode.color = "";
	clearNode.date = "";
	clearNode.model = "";
	clearNode.name = "";
	clearNode.number = "";
	clearNode.surname = "";
	for (int i = 1; i <= length; i++) {
		table[i-1] = clearNode;
	}
}

//Метод хеширования ключа
long long HashTable::hashCode(Node node) {
	long long hashCode=0;
	for (int i = 0; i < node.number.length(); i++) {
		hashCode += (long long)node.number[i]<<5;
		hashCode += ((node.number[i] << 1) * 133 / 53)<<4;
	}
	
	for (int i = 0; i < node.surname.length(); i++) {
		hashCode += (long long)node.surname[i]<<3;
		hashCode += ((node.surname[i] << 1) * 57 / 7)<<3 ;
	}

	for (int i = 0; i < node.date.length(); i++) {
		hashCode += (long long)node.date[i]<<8;
		hashCode += (long long)(node.date[i] * 3 +997)>>13 ;
	}

	for (int i = 0; i < node.model.length(); i++) {
		hashCode += (long long)node.model [i] << 8;
		hashCode += (long long)(node.model[i] * 997) << 1;
	}

	for (int i = 0; i < node.name.length(); i++) {
		hashCode += (long long)node.name[i] << 8;
	}

	for (int i = 0; i < node.color.length(); i++) {
		hashCode += (long long)node.color[i] << 8;
	}
	hashCode += hashCode<<3;
	hashCode ^= hashCode >> 2;
	hashCode += hashCode << 5;
	hashCode = hashCode % length;

	return hashCode;
}

//Метод вставки ключа в хеш-таблицу
bool HashTable::pasteKey(Node node) {
	int index = hashCode(node);

	for (int i = index+1; i <= length; i++) {
		string check = table[i-1].color + table[i-1].date + table[i-1].model + table[i-1].name + table[i-1].number + table[i-1].surname;

		if (check.length() == 0) {
			table[i-1] = node;
			break;
		}
		if (i == length) i = 0;
		if (i == index) return false;
	}
	totalNodes += 1;
	rehashTable();
	return true;
}
//Метод удаления ключа из хеш-таблицы
bool HashTable::deleteKey(Node node) {
	int index = hashCode(node);

	for (int i = index+1; i <= length; i++) {

		if (table[i-1].color == node.color && table[i-1].date == node.date && table[i-1].model == node.model && table[i-1].name == node.name && table[i-1].number == node.number && table[i-1].surname == node.surname) {
			
			table[i-1].color = "";
			table[i-1].date = "";
			table[i-1].model = "";
			table[i-1].name = "";
			table[i-1].number = "";
			table[i-1].surname = "";

			break;
		}
		if (i == length) i = 0;
		if (i == index) return false;
	}
	totalNodes -= 1;
	return true;
}

//Метод поиска ключа в хеш-таблице
int HashTable::findKey(Node node) {
	int index = hashCode(node);

	for (int i = index+1; i <= length; i++) {

		if (table[i-1].color == node.color &&
			table[i-1].date == node.date &&
			table[i-1].model == node.model &&
			table[i-1].name == node.name &&
			table[i-1].number == node.number &&
			table[i-1].surname == node.surname) {

			return i-1;
		}
		if (i == length) i = 0;
		if (i == index) return -1;
	}
}

//Метод рехеширования хеш-таблицы.
void HashTable::rehashTable() {
	if (totalNodes > length / 2) {
		Node* copy = new Node[length];
		for (int i = 0; i < length; i++) {
			copy[i] = table[i];
		}

		table = new Node[length * 5];

		int oldIndex = length;
		length *= 5;
		totalNodes = 0;

		for (int i = 0; i < oldIndex; i++) {
			pasteKey(copy[i]);
		}

	}
}

//Метод вывода хеш-таблицы на экран
void HashTable::outputTable() {
	for (int i = 0; i < length; i++) {
		cout <<setw(5)<< i << " | ";
		cout << table[i].number << " ";
		cout << table[i].model << " ";
		cout << table[i].color << " ";
		cout << table[i].surname << " ";
		cout << table[i].name << " ";
		cout << table[i].date << "\n";
	}
}

//Функция тестирования хеш-таблицы
void testHeshT() {
	int len = 10;
	HashTable table(len);
	
	Node noCols1;
	Node noCols2;

	Node cols1;
	Node cols2;
	Node cols3;
	Node cols4;
	//U156ZJ CSO R OVFNQS CN 13.80.5713
	noCols1.color="R";
	noCols1.date="13.80.5713";
	noCols1.model="CSO";
	noCols1.name="CN";
	noCols1.number="U156ZJ";
	noCols1.surname="OVFNQS";
	cout << "Хеш 1: " << table.hashCode(noCols1)<<endl;

	//X617JG ZCQ Q KTKOVR LB 62.35.8929
	noCols2.color="Q";
	noCols2.date="62.35.8929";
	noCols2.model="ZCQ";
	noCols2.name="LB";
	noCols2.number="X617JG";
	noCols2.surname="KTKOVR";
	cout << "Хеш 2: " << table.hashCode(noCols2) << endl;

	table.pasteKey(noCols1);
	table.pasteKey(noCols2);
	table.outputTable();
	cout << endl;

	//P371DD IYV C NZKTMN NW 73.49.5453
	cols1.color = "C";
	cols1.date = "73.49.5453";
	cols1.model = "IYV";
	cols1.name = "NW";
	cols1.number = "P371DD";
	cols1.surname = "NZKTMN";
	cout << "Хеш 1 (cols): " << table.hashCode(cols1) << endl;

	//V716HW EHT Z ASMNEK UT 77.41.5535
	cols2.color = "Z";
	cols2.date = "77.41.5535";
	cols2.model = "EHT";
	cols2.name = "UT";
	cols2.number = "V716HW";
	cols2.surname = "ASMNEK";
	cout << "Хеш 2 (cols): " << table.hashCode(cols2) << endl;

	//J932PU WXI V MYGTCT FO 28.05.2617
	cols3.color = "V";
	cols3.date = "28.05.2617";
	cols3.model = "WXI";
	cols3.name = "FO";
	cols3.number = "J932PU";
	cols3.surname = "MYGTCT";
	cout << "Хеш 3 (cols): " << table.hashCode(cols3) << endl;

	//X015TI LCM T XSPUAH MC 22.58.9276
	cols4.color = "T";
	cols4.date = "22.58.9276";
	cols4.model = "LCM";
	cols4.name = "MC";
	cols4.number = "X015TI";
	cols4.surname = "XSPUAH";
	cout << "Хеш 4 (cols): " << table.hashCode(cols3) << endl;

	table.pasteKey(cols1);
	table.pasteKey(cols2);
	table.pasteKey(cols3);
	table.outputTable();
	cout << endl;

	table.pasteKey(cols4);
	table.outputTable();
	cout << endl;

	cout << "Удаляемый ключ: V716HW EHT Z ASMNEK UT 77.41.5535\n";
	table.deleteKey(cols2);
	table.outputTable();
	cout << endl;

	cout << "Искомый ключ: J932PU WXI V MYGTCT FO 28.05.2617" << endl;
	cout << "Индекс искомого ключа: " << table.findKey(cols3);
}

//int main() {
//	Node node;
//	node.number = "P371DD";
//	node.model = "IYV";
//	node.color = "C";
//	node.surname = "NZKTMN";
//	node.name = "NW";
//	node.date = "73.49.5453";
//
//	HashTable table(5000);
//
//	//cout << table.hashCode(node); // 4428
//
//	fstream fin("databig.txt", ios::in);
//	string line;
//	while (getline(fin,line)){
//		stringstream ss(ios::in | ios::out);
//
//		ss << line;
//
//		Node node2;
//		ss >> node2.number;
//		ss >> node2.model;
//		ss >> node2.color;
//		ss >> node2.surname;
//		ss >> node2.name;
//		ss >> node2.date;
//
//		if (table.hashCode(node2) == table.hashCode(node)) cout << line<<endl;
//	}
//
//
//}