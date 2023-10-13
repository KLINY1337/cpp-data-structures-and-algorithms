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

		cout << "Лабораторная работа №5 \"Сбалансированные деревья поиска (СДП) и их применение для поиска данных в файле\". Черномуров Семён\n";

		cout << "Выберите номер задания:\n1) Создать бинарный файл записей из текстового.\n" <<
			"2) Поиск записи в файле с помощью линейного поиска.\n" <<
			"3) Поиск записи по ее адресу.\n" <<
			"4) Добавить запись в файл.\n" <<
			"5) Построить бинарное дерево по файлу.\n" <<
			"6) Добавить элемент в бинарное дерево.\n"<<
			"7) Поиск по ключу в бинарном дереве.\n"<<
			"8) Удаление элемента из бинарного дерева.\n"<<
			"9) Вывод бинарного дерева на экран.\n"<<
			"10) Построить АВЛ-дерево по файлу.\n"<<
			"11) Добавить элемент в АВЛ-дерево.\n"<<
			"12) Поиск по ключу в АВЛ-дереве.\n"<<
			"13) Удаление элемента из АВЛ-дерева.\n"<<
			"14) Вывод АВЛ-дерева на экран.\n"<<
			"15) Проверка работы деревьев на больших данных.\n"<<
			"0) Завершить работу программы.\n\n";



		int choice1;
		do {
			cin >> choice1;

			if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 6 && choice1 != 7 && choice1 != 8 && choice1 != 9 && choice1 != 10 && choice1 != 11 && choice1 != 12 && choice1 != 13 && choice1 != 14 && choice1 != 15 && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
		} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 6 && choice1 != 7 && choice1 != 8 && choice1 != 9 && choice1 != 10 && choice1 != 11 && choice1 != 12 && choice1 != 13 && choice1 != 14 && choice1 != 15 && choice1 != 0);
		
		system("cls");
		switch (choice1)
		{
		case 1: {
			cout << "Введите название текстового файла: ";
			string txt;
			cin >> txt;

			cout << "Введите название бинарного файла: ";
			string bin;
			cin >> bin;
			

			binTree.createBinFile(txt, bin);
			avlTree.createBinFile(txt, bin);

			cout << "Бинарный файл успешно создан.";
			break;
		}
		case 2: {
			cout << "Введите уникальный номер записи: ";
			string number;
			cin >> number;

			Node node=binTree.printByKey(number);

			cout<<"Номер найденной записи в файле: "<<binTree.getAddressByKey(node.number);
			break;
		}
		case 3: {
			cout << "Введите адрес записи в файле (начиная с 0): ";
			int address;
			cin >> address;

			Node node=binTree.printByAddress(address);
			cout << "По введенному адресу была найдена запись: " << string(node.number) << " " << string(node.surname) << " " << string(node.name) << " " << string(node.father);
			break;
		}
		case 4: {
			cout << "Введите номер счета: ";
			string number;
			cin >> number;

			cout << "Введите фамилию: ";
			string surname;
			cin >> surname;

			cout << "Введите имя: ";
			string name;
			cin >> name;

			cout << "Введите отчество: ";
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
			cout << "Бинарное дерево создано по файлу.";
			break;
		}
		case 6: {
			cout << "Введите номер добавляемой записи: ";
			string number;
			cin >> number;
			binTree.insert(number);
			cout << "Запись успешно вставлена.";
			break;
		}
		case 7: {
			cout << "Введите ключ для поиска: ";
			string number;
			cin >> number;

			BinTreeNode* node=binTree.findByKey(number);
			Node node2= binTree.printByKey(string(node->number));
			cout << "По введенному ключу была найдена запись: " << string(node2.number) << " " << string(node2.surname) << " " << string(node2.name) << " " << string(node2.father);
			break;
		}
		case 8: {
			cout << "Введите ключ удаляемой записи: ";
			string key;
			cin >> key;

			binTree.deleteByKey(key);
			cout << "Запись успешно удалена";
			break;
		}
		case 9: {
			binTree.printHor();
			break;
		}
		case 10: {
			avlTree.createFromFile();
			cout << "АВЛ-дерево создано по файлу.";
			break;
		}
		case 11: {
			cout << "Введите номер добавляемой записи: ";
			string number;
			cin >> number;
			avlTree.insert(number);
			cout << "Запись успешно вставлена.";
			break;
		}
		case 12: {
			cout << "Введите ключ для поиска: ";
			string number;
			cin >> number;

			AVLNode* node = avlTree.findByKey(number);
			Node node2 = avlTree.printByKey(string(node->number));
			cout << "По введенному ключу была найдена запись: " << string(node2.number) << " " << string(node2.surname) << " " << string(node2.name) << " " << string(node2.father);
			break;
		}
		case 13: {
			cout << "Введите ключ удаляемой записи: ";
			string key;
			cin >> key;

			avlTree.deleteByKey(key);
			cout << "Запись успешно удалена";
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
			cout << "Линейный поиск (начало): ";
			auto start = chrono::steady_clock::now();
			file.getAddressByKey(keyStart);
			auto end = chrono::steady_clock::now();
			cout<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносек" << endl;
			cout << "Поиск в бинарном дереве (начало): ";
			auto start2 = chrono::steady_clock::now();
			BT.findByKey(keyStart);
			auto end2 = chrono::steady_clock::now();
			cout<< chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << " наносек" << endl;
			cout << "Поиск в АВЛ-дереве (начало): ";
			auto start3 = chrono::steady_clock::now();
			AVL.findByKey(keyStart);
			auto end3 = chrono::steady_clock::now();
			cout << chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count() << " наносек";

			cout << "\n\n";

			cout << "Линейный поиск (середина): ";
			start = chrono::steady_clock::now();
			file.getAddressByKey(keyMiddle);
			end = chrono::steady_clock::now();
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносек" << endl;
			cout << "Поиск в бинарном дереве (середина): ";
			start2 = chrono::steady_clock::now();
			BT.findByKey(keyMiddle);
			end2 = chrono::steady_clock::now();
			cout<<chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << " наносек" << endl;
			cout << "Поиск в АВЛ-дереве (середина): ";
			start3 = chrono::steady_clock::now();
			AVL.findByKey(keyMiddle);
			end3 = chrono::steady_clock::now();
			cout << chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count() << " наносек";

			cout << "\n\n";

			cout << "Линейный поиск (конец): ";
			start = chrono::steady_clock::now();
			file.getAddressByKey(keyEnd);
			end = chrono::steady_clock::now();
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносек" << endl;
			cout << "Поиск в бинарном дереве (конец): ";
			start2 = chrono::steady_clock::now();
			BT.findByKey(keyEnd);
			end2 = chrono::steady_clock::now();
			cout << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << " наносек" << endl;
			cout << "Поиск в АВЛ-дереве (конец): ";
			start3 = chrono::steady_clock::now();
			AVL.findByKey(keyEnd);
			end3 = chrono::steady_clock::now();
			cout << chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count() << " наносек";

			cout << "\n\n";

			double avg = AVL.rotationsAmount*1.0 / file.nodesAmount;
			cout << "Среднее число поворотов = " << avg << " пов/ключ";

			break;


		}
		case 0:
			return 0;
		}
		cout << "\n\n";

		main();
}