#pragma once
#include "hash_table.h"

void pasteEl(string file_name, HashTable& table, string index);
void deleteEl(string file_name, HashTable& table, string line);
string findEl(string file_name, HashTable& table, Node node);