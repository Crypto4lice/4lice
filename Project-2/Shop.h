#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Item.h"
using std::string;
using std::ifstream;
using std::vector;

class Shop {
public:
	Shop();
	Shop(string name, string filename);
	Shop(string name, vector<Item*> items);
	void ReadDataFromFile();
	void ShowItemList();
private:
	vector<Item*> item; // value for read data

	string shop_name;
	string filename;
	ifstream inputstream;
};