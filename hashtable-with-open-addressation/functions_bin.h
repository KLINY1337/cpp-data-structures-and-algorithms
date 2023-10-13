#pragma once
#include <string>
#include <iostream>
using namespace std;

void fileInput(string file_name, string data);
string fileOutput(string file_name);

void textToBin(string file_name_txt, string file_name_bin);
void fileOutputBin(string file_name);
string fileGet(string file_name, string index);
void fileDelete(string file_name, string line);

void testBinF();