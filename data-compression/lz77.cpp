#include "lz77.h"
#include <iostream>
using namespace std;

// ����� ������ ������� LZ77
std::vector<LZ77::Node> LZ77::compress(const std::string data) {
	vector<Node> answer = {};
	string buffer = "";

	for (int i = 0; i < data.size(); i++) {
		if (buffer.find(data[i]) == -1) { //���� ������ �����
			buffer += data[i]; 
			Node node;
			node.length = 0;
			node.offset = 0;
			node.next = data[i];
			answer.push_back(node);
			continue;
		}
		else {
			for (int j = min(buffer.size(), data.size() - i); j > 0; j--) { // ��� ���� �������� ������ ������ �� 1 �� (������� �������� ������) 
				string stringToFind = "";
				for (int k = i; k < j + i; k++) { // ������� ��� ���������
					stringToFind += data[k];
				}
				if (buffer.find(stringToFind) != -1) {
					int offset = buffer.size() - buffer.rfind(stringToFind);
					int length = stringToFind.size();
					Node node;
					node.length = length;
					node.offset = offset;
					node.next = '\0';
					answer.push_back(node);
					buffer += stringToFind;
					i += stringToFind.size() - 1;
					break;
				}
			}
		}


	}
	return answer;
}

