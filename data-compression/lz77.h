#pragma once
#ifndef LZ77_H
#define LZ77_H

#include <vector>
#include <string>



class LZ77
{
public:
	struct Node {
		int offset;
		int length;
		char next;
	};

	static std::vector<Node> compress(const std::string data);

};
#endif // !LZ77_H
