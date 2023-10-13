#include "rle.h"
#include <iostream>
using namespace std;

// Метод сжатия методом RLE
string RLE::compress(string data) {
	if (data == "") return "";

	string compressedData = "", buffer = "";
	buffer += data[0];

	for (int i = 1; i < data.size(); i++) {
		if (buffer[0] == data[i] || buffer == "") buffer += data[i];
		if (buffer[0] != data[i] || i == data.size()-1) {
			compressedData += buffer[0];
			compressedData += to_string(buffer.size());
			compressedData += " ";
			buffer = data[i];
		}
	}
	if (buffer != "") {
		compressedData += buffer[0];
		compressedData += to_string(buffer.size());
	}
	return compressedData.erase(compressedData.size()-3,3);
}

