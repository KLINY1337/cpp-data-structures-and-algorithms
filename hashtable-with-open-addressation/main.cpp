#include "functions_bin.h"
#include "functions_main.h"
#include "hash_table.h"

#include <chrono>
#include <sstream>
#include <fstream>

HashTable table(10);

int main() {
	setlocale(LC_ALL, "");
	
	cout << "������������ ������ �3 \"���������� ���-������� ��� ������ ������ � �������� ����� � �������� ������������� �����\". ���������� ����\n";

	cout << "�������� ����� �������:\n1) �������� ������� testHeshT.\n" <<
		"2) �������� ������� testBinF.\n" <<
		"3) ��������� ������ �� ����� � �������� ������� � �������.\n" <<
		"4) ������� ������ �� ������� � ����� ��� �������� �������� �����.\n" <<
		"5) ����� ������ � ����� �� �������� �����.\n" <<
		"6) �������� ������������� ������ � ���-������� ��� ������� ���������� ������.\n" <<
		"0) ��������� ������ ���������.\n\n";

	

	int choice1;
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 6 && choice1 != 0) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 6 && choice1 != 0);

	system("cls");

	switch (choice1)
	{
	case 1: {
		testHeshT();
		break;
	}
	case 2: {
		testBinF();
		break;
	}
	case 3: {
		cout << "������� �������� �����: ";
		string file_name;
		cin >> file_name;
		cout << "������� ������ ��������: ";
		string index;
		cin >> index;

		pasteEl(file_name, table, index);
		cout << "���-�������:\n";
		table.outputTable();
		break;
	}
	case 4: {
		cout << "������� �������� �����: ";
		string file_name;
		cin >> file_name;
		cout << "������� ���� ��������: ";
		string line;
		cin.ignore(32767, '\n');
		getline(cin, line);
		cout << "�������� ���-�������:\n";
		table.outputTable();
		cout << "\n\n";
		cout << "�������� �������� ����:\n";
		fileOutputBin(file_name);
		cout << "\n\n";
		deleteEl(file_name, table, line);
		cout << "���������������� ���-�������:\n";
		table.outputTable();
		cout << "\n\n";
		cout << "���������������� �������� ����:\n";
		fileOutputBin(file_name);
		break;
	}
	case 5: {
		cout << "������� �������� �����: ";
		string file_name;
		cin >> file_name;
		cout << "������� ���� ��������: ";
		string line;
		cin.ignore(32767, '\n');
		getline(cin, line);

		stringstream ss(ios::in | ios::out);
		ss << line;

		Node node;
		ss >> node.number;
		ss >> node.model;
		ss >> node.color;
		ss >> node.surname;
		ss >> node.name;
		ss >> node.date;

		cout<<"��������� ������ � �����: " << findEl(file_name, table, node);
		break;
	}
	case 6: {
		string file_name = "databigbin.bin";
		textToBin("databig.txt", "databigbin.bin");

		HashTable tablebig(5000);
		cout << "f";
		string line;

		fstream fin(file_name, ios::in | ios::binary);
		int i = 0;
		while (getline(fin, line)) {
			stringstream ss(ios::in | ios::out);
			ss << line;
			Node node;
			ss >> node.number;
			ss >> node.model;
			ss >> node.color;
			ss >> node.surname;
			ss >> node.name;
			ss >> node.date;
			tablebig.pasteKey(node);
			i++;
			if (i % 500 == 0) cout << i << endl;
		}
		cout << "������� ������ ���������.\n";
		fin.close();

		stringstream ss(ios::in | ios::out);
		ss << "V873AM ZPD U BRWEUH DH 03.46.0459";
		Node node1;
		ss >> node1.number;
		ss >> node1.model;
		ss >> node1.color;
		ss >> node1.surname;
		ss >> node1.name;
		ss >> node1.date;

		stringstream ss2(ios::in | ios::out);
		ss2 << "I844WM QWH V LKNFDJ MZ 06.87.3722";
		Node node2;
		ss2 >> node2.number;
		ss2 >> node2.model;
		ss2 >> node2.color;
		ss2 >> node2.surname;
		ss2 >> node2.name;
		ss2 >> node2.date;

		stringstream ss3(ios::in | ios::out);
		ss3 << "V438UU ACE M SBIBCS JS 99.01.8490";
		Node node3;
		ss3 >> node3.number;
		ss3 >> node3.model;
		ss3 >> node3.color;
		ss3 >> node3.surname;
		ss3 >> node3.name;
		ss3 >> node3.date;

		auto start = chrono::steady_clock::now();
		tablebig.findKey(node1);
		auto end = chrono::steady_clock::now();
		cout << "����� ������ ������: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " �������" << endl;

		auto start2 = chrono::steady_clock::now();
		tablebig.findKey(node2);
		auto end2 = chrono::steady_clock::now();
		cout << "����� ������� ������: " << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count()<< " �������" <<endl;

		auto start3 = chrono::steady_clock::now();
		tablebig.findKey(node3);
		auto end3 = chrono::steady_clock::now();
		cout << "����� ��������� ������: " << chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count()<< " �������";
		break;
	}

	case 0:
		return 0;
	}
	cout << "\n\n";
	//textToBin("data.txt", "databin.bin");
	main();
}