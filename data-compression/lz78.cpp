#include "lz78.h"
#include <algorithm>
#include <iostream>
using namespace std;

//Метод сжатия методом LZ78
vector<LZ78::Node> LZ78::compress(const string data) {
	vector<string> dictionary = {};
	vector<LZ78::Node> answer = {};
	string stringToFind = "";
	int position = 0;
	while (position < data.size()) {
		while (find(dictionary.begin(), dictionary.end(), stringToFind) != dictionary.end()) {
			stringToFind += data[position];
			position++;
		}
		if (stringToFind != "") {
			int positionInDictionary = 0;
			char lastSymbol = stringToFind[stringToFind.size() - 1];
			string cuttedString = stringToFind;
			cuttedString.pop_back();
			if (find(dictionary.begin(), dictionary.end(), cuttedString) != dictionary.end()) {
				positionInDictionary = distance(dictionary.begin(), find(dictionary.begin(), dictionary.end(), cuttedString)); // номер слова по итератору
			}
			Node node;
			node.next = lastSymbol;
			node.position = positionInDictionary;
			answer.push_back(node);
		}
		dictionary.push_back(stringToFind);
		stringToFind = "";
	}
	return answer;
}

