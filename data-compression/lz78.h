#pragma once
#ifndef LZ78_H
#define LZ78_H

#include <vector>
#include <string>

class LZ78
{
public:
	struct Node {
		int position;
		char next;
	};
	static std::vector<Node> compress(const std::string data);
};

#endif // !LZ78_H
