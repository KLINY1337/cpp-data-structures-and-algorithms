#include "bin_file.h"
#include "bin_tree.h"
#include "balanced_tree.h"
#include <iostream>
#include <chrono>
using namespace std;

BinaryTree binTree;
AVLTree avlTree;

int main() {
		setlocale(LC_ALL, "");

		cout << "������������ ������ �5 \"���������������� ������� ������ (���) � �� ���������� ��� ������ ������ � �����\". ���������� ����\n";

		cout << "�������� ����� �������:\n1) ������� �������� ���� ������� �� ����������.\n" <<
			"2) ����� ������ � ����� � ������� ��������� ������.\n" <<
			"3) ����� ������ �� �� ������.\n" <<
			"4) �������� ������ � ����.\n" <<
			"5) ��������� �������� ������ �� �����.\n" <<
			"6) �������� ������� � �������� ������.\n"<<
			"7) ����� �� ����� � �������� ������.\n"<<
			"8) �������� �������� �� ��������� ������.\n"<<
			"9) ����� ��������� ������ �� �����.\n"<<
			"10) ��������� ���-������ �� �����.\n"<<
			"11) �������� ������� � ���-������.\n"<<
			"12) ����� �� ����� � ���-������.\n"<<
			"13) �������� �������� �� ���-������.\n"<<
			"14) ����� ���-������ �� �����.\n"<<
			"15) �������� ������ �������� �� ������� ������.\n"<<
			"0) ��������� ������ ���������.\n\n";



		int choice1;
		do {
			cin >> choice1;

			if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 6 && choice1 != 7 && choice1 != 8 && choice1 != 9 && choice1 != 10 && choice1 != 11 && choice1 != 12 && choice1 != 13 && choice1 != 14 && choice1 != 15 && choice1 != 0) cout << "������� �������� ��������, ���������� �����.\n";
		} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 6 && choice1 != 7 && choice1 != 8 && choice1 != 9 && choice1 != 10 && choice1 != 11 && choice1 != 12 && choice1 != 13 && choice1 != 14 && choice1 != 15 && choice1 != 0);
		
		system("cls");
		switch (choice1)
		{
		case 1: {
			cout << "������� �������� ���������� �����: ";
			string txt;
			cin >> txt;

			cout << "������� �������� ��������� �����: ";
			string bin;
			cin >> bin;
			

			binTree.createBinFile(txt, bin);
			avlTree.createBinFile(txt, bin);

			cout << "�������� ���� ������� ������.";
			break;
		}
		case 2: {
			cout << "������� ���������� ����� ������: ";
			string number;
			cin >> number;

			Node node=binTree.printByKey(number);

			cout<<"����� ��������� ������ � �����: "<<binTree.getAddressByKey(node.number);
			break;
		}
		case 3: {
			cout << "������� ����� ������ � ����� (������� � 0): ";
			int address;
			cin >> address;

			Node node=binTree.printByAddress(address);
			cout << "�� ���������� ������ ���� ������� ������: " << string(node.number) << " " << string(node.surname) << " " << string(node.name) << " " << string(node.father);
			break;
		}
		case 4: {
			cout << "������� ����� �����: ";
			string number;
			cin >> number;

			cout << "������� �������: ";
			string surname;
			cin >> surname;

			cout << "������� ���: ";
			string name;
			cin >> name;

			cout << "������� ��������: ";
			string father;
			cin >> father;

			Node* node=new Node();
			number.copy(node->number, 7);
			surname.copy(node->surname, 7);
			name.copy(node->name, 7);
			father.copy(node->father, 7);
			binTree.pasteNode(node);
			break;
		}
		case 5: {
			binTree.createFromFile();
			cout << "�������� ������ ������� �� �����.";
			break;
		}
		case 6: {
			cout << "������� ����� ����������� ������: ";
			string number;
			cin >> number;
			binTree.insert(number);
			cout << "������ ������� ���������.";
			break;
		}
		case 7: {
			cout << "������� ���� ��� ������: ";
			string number;
			cin >> number;

			BinTreeNode* node=binTree.findByKey(number);
			Node node2= binTree.printByKey(string(node->number));
			cout << "�� ���������� ����� ���� ������� ������: " << string(node2.number) << " " << string(node2.surname) << " " << string(node2.name) << " " << string(node2.father);
			break;
		}
		case 8: {
			cout << "������� ���� ��������� ������: ";
			string key;
			cin >> key;

			binTree.deleteByKey(key);
			cout << "������ ������� �������";
			break;
		}
		case 9: {
			binTree.printHor();
			break;
		}
		case 10: {
			avlTree.createFromFile();
			cout << "���-������ ������� �� �����.";
			break;
		}
		case 11: {
			cout << "������� ����� ����������� ������: ";
			string number;
			cin >> number;
			avlTree.insert(number);
			cout << "������ ������� ���������.";
			break;
		}
		case 12: {
			cout << "������� ���� ��� ������: ";
			string number;
			cin >> number;

			AVLNode* node = avlTree.findByKey(number);
			Node node2 = avlTree.printByKey(string(node->number));
			cout << "�� ���������� ����� ���� ������� ������: " << string(node2.number) << " " << string(node2.surname) << " " << string(node2.name) << " " << string(node2.father);
			break;
		}
		case 13: {
			cout << "������� ���� ��������� ������: ";
			string key;
			cin >> key;

			avlTree.deleteByKey(key);
			cout << "������ ������� �������";
			break;
		}
		case 14: {
			avlTree.printHor();
			break;
		}
		case 15: {
			string keyStart = "3430618";
			string keyMiddle = "3266879";
			string keyEnd = "7223343";

			BinFile file;
			file.createBinFile("databig.txt", "databig.bin");

			BinaryTree BT;
			BT.createBinFile("databig.txt", "databig.bin");
			BT.createFromFile();

			AVLTree AVL;
			AVL.createBinFile("databig.txt", "databig.bin");
			AVL.createFromFile();
			cout << "�������� ����� (������): ";
			auto start = chrono::steady_clock::now();
			file.getAddressByKey(keyStart);
			auto end = chrono::steady_clock::now();
			cout<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " �������" << endl;
			cout << "����� � �������� ������ (������): ";
			auto start2 = chrono::steady_clock::now();
			BT.findByKey(keyStart);
			auto end2 = chrono::steady_clock::now();
			cout<< chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << " �������" << endl;
			cout << "����� � ���-������ (������): ";
			auto start3 = chrono::steady_clock::now();
			AVL.findByKey(keyStart);
			auto end3 = chrono::steady_clock::now();
			cout << chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count() << " �������";

			cout << "\n\n";

			cout << "�������� ����� (��������): ";
			start = chrono::steady_clock::now();
			file.getAddressByKey(keyMiddle);
			end = chrono::steady_clock::now();
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " �������" << endl;
			cout << "����� � �������� ������ (��������): ";
			start2 = chrono::steady_clock::now();
			BT.findByKey(keyMiddle);
			end2 = chrono::steady_clock::now();
			cout<<chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << " �������" << endl;
			cout << "����� � ���-������ (��������): ";
			start3 = chrono::steady_clock::now();
			AVL.findByKey(keyMiddle);
			end3 = chrono::steady_clock::now();
			cout << chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count() << " �������";

			cout << "\n\n";

			cout << "�������� ����� (�����): ";
			start = chrono::steady_clock::now();
			file.getAddressByKey(keyEnd);
			end = chrono::steady_clock::now();
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " �������" << endl;
			cout << "����� � �������� ������ (�����): ";
			start2 = chrono::steady_clock::now();
			BT.findByKey(keyEnd);
			end2 = chrono::steady_clock::now();
			cout << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << " �������" << endl;
			cout << "����� � ���-������ (�����): ";
			start3 = chrono::steady_clock::now();
			AVL.findByKey(keyEnd);
			end3 = chrono::steady_clock::now();
			cout << chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count() << " �������";

			cout << "\n\n";

			double avg = AVL.rotationsAmount*1.0 / file.nodesAmount;
			cout << "������� ����� ��������� = " << avg << " ���/����";

			break;


		}
		case 0:
			return 0;
		}
		cout << "\n\n";

		main();
}