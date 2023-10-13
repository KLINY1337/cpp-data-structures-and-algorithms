#pragma once
#ifndef SHANNON_H
#define SHANNON_H

#include <string>
#include <vector>

class ShannonFano {
private:
	struct Node {
		char symbol;
		float probability;
	};
	struct Code {
		char symbol;
		std::string code="";
	};

	std::vector<Node> probabilities;
	std::vector<Code> codes;

	std::string data;


	std::vector<Node> getProbabilities(const std::string data);
	int separate(std::vector<Node>);
	void getCodes(std::vector<Node> probabilities, std::string code);
public:
	
	std::string compressedData="";
	ShannonFano(const std::string data);
	void decompress();
};

#endif // !SHANNON_H
