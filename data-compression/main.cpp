#include "rle.h"
#include "lz77.h"
#include "lz78.h"
#include "shannon-fano.h"
#include "haffman.h"
#include <iostream>
#include <windows.h>
using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");

	cout << "������������ ������ �7 \"����������� � ������ ������ �������� ��� ������\". ���������� ����\n";

	cout << "�������� ����� �������:\n" <<
		"1) RLE-������\n" <<
		"2) LZ77-������\n" <<
		"3) LZ78-������\n" <<
		"4) ������ ������� �������-����\n" <<
		"5) ������ ������� ��������\n" <<
		"0) ��������� ������ ���������.\n\n";

	int choice1;
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 0) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 0);

	system("cls");
	switch (choice1)
	{
	case 1: {
		cout << "������� ��������� �����:\n";
		string data;
		cin.ignore(32767, '\n');
		getline(cin, data);
		string compressedData = RLE::compress(data);
		cout << "��������� ������:\n" << compressedData;
		cout << "\n\n" << "����������� ������: " << data.size() * 1.0 / compressedData.size();
		break;
	}
	case 2: {
		cout << "������� ��������� �����:\n";
		string data;
		cin.ignore(32767, '\n');
		getline(cin, data);
		vector<LZ77::Node> compressedData = LZ77::compress(data);
		cout << "��������� ������:\n";
		for (int i = 0; i < compressedData.size(); i++) {
			cout << "<" << compressedData[i].offset << "," << compressedData[i].length << ">" << compressedData[i].next<<" ";
		}
		cout << "\n\n" << "����������� ������: " << data.size() * 1.0 / compressedData.size();
		break;
	}
	case 3: {
		cout << "������� ��������� �����:\n";
		string data;
		cin.ignore(32767, '\n');
		getline(cin, data);
		vector<LZ78::Node> compressedData = LZ78::compress(data);
		cout << "��������� ������:\n";
		for (int i = 0; i < compressedData.size(); i++) {
			cout << "<" << compressedData[i].position << "," << compressedData[i].next << "> ";
		}
		cout << "\n\n" << "����������� ������: " << data.size() * 1.0 / compressedData.size();
		break;
	}
	case 4: {

		cout << "������� ��������� �����:\n";
		string data;
		cin.ignore(32767, '\n');
		getline(cin, data);
		ShannonFano obj(data);
		cout << "��������� ������:\n";
		cout << obj.compressedData<<"\n";
		cout << "������� �������������� ������: ";
		obj.decompress();

		cout << "\n\n" << "����������� ������: " << data.size() * 8.0 / obj.compressedData.size();
		break;
	}

	case 5: {
		cout << "������� ��������� �����:\n";
		string data;
		cin.ignore(32767, '\n');
		getline(cin, data);
		Haffman obj(data);
		cout << "��������� ������:\n";
		cout << obj.compressedData << "\n";
		cout << "������� �������������� ������: ";
		obj.decompress();

		cout << "\n\n" << "����������� ������: " << data.size() * 8.0 / obj.compressedData.size();
		break;
	}
	case 0:
		return 0;
	}
	cout << "\n\n";

	main();
}