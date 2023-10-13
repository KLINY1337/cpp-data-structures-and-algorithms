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

	cout << "Лабораторная работа №7 \"Кодирование и сжатие данных методами без потерь\". Черномуров Семён\n";

	cout << "Выберите номер задания:\n" <<
		"1) RLE-сжатие\n" <<
		"2) LZ77-сжатие\n" <<
		"3) LZ78-сжатие\n" <<
		"4) Сжатие методом Шеннона-Фано\n" <<
		"5) Сжатие методом Хаффмана\n" <<
		"0) Завершить работу программы.\n\n";

	int choice1;
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 0);

	system("cls");
	switch (choice1)
	{
	case 1: {
		cout << "Введите сжимаемый текст:\n";
		string data;
		cin.ignore(32767, '\n');
		getline(cin, data);
		string compressedData = RLE::compress(data);
		cout << "Результат сжатия:\n" << compressedData;
		cout << "\n\n" << "Коэффициент сжатия: " << data.size() * 1.0 / compressedData.size();
		break;
	}
	case 2: {
		cout << "Введите сжимаемый текст:\n";
		string data;
		cin.ignore(32767, '\n');
		getline(cin, data);
		vector<LZ77::Node> compressedData = LZ77::compress(data);
		cout << "Результат сжатия:\n";
		for (int i = 0; i < compressedData.size(); i++) {
			cout << "<" << compressedData[i].offset << "," << compressedData[i].length << ">" << compressedData[i].next<<" ";
		}
		cout << "\n\n" << "Коэффициент сжатия: " << data.size() * 1.0 / compressedData.size();
		break;
	}
	case 3: {
		cout << "Введите сжимаемый текст:\n";
		string data;
		cin.ignore(32767, '\n');
		getline(cin, data);
		vector<LZ78::Node> compressedData = LZ78::compress(data);
		cout << "Результат сжатия:\n";
		for (int i = 0; i < compressedData.size(); i++) {
			cout << "<" << compressedData[i].position << "," << compressedData[i].next << "> ";
		}
		cout << "\n\n" << "Коэффициент сжатия: " << data.size() * 1.0 / compressedData.size();
		break;
	}
	case 4: {

		cout << "Введите сжимаемый текст:\n";
		string data;
		cin.ignore(32767, '\n');
		getline(cin, data);
		ShannonFano obj(data);
		cout << "Результат сжатия:\n";
		cout << obj.compressedData<<"\n";
		cout << "Обратно декодированная строка: ";
		obj.decompress();

		cout << "\n\n" << "Коэффициент сжатия: " << data.size() * 8.0 / obj.compressedData.size();
		break;
	}

	case 5: {
		cout << "Введите сжимаемый текст:\n";
		string data;
		cin.ignore(32767, '\n');
		getline(cin, data);
		Haffman obj(data);
		cout << "Результат сжатия:\n";
		cout << obj.compressedData << "\n";
		cout << "Обратно декодированная строка: ";
		obj.decompress();

		cout << "\n\n" << "Коэффициент сжатия: " << data.size() * 8.0 / obj.compressedData.size();
		break;
	}
	case 0:
		return 0;
	}
	cout << "\n\n";

	main();
}