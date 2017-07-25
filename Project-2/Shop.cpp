#include "Shop.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;

/* 
	vector templete split reference
	https://stackoverflow.com/questions/236129/most-elegant-way-to-split-a-string
*/

template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

Shop::Shop()
{
}

Shop::Shop(string name, string filename)
	: shop_name(name), filename(filename)
{
	try { 
		inputstream.open(filename);
		ReadDataFromFile();
	}
	catch (exception e) {
		cout << "file not exist" << endl;
	}
}

Shop::Shop(string name, std::vector<Item*> item)
	: shop_name(name), item(item)
{
}

void Shop::ReadDataFromFile()
{
	vector<string> readline;
	string buffer;
	// read file data as line and store each vector array
	while (getline(inputstream, buffer)) {
		readline.push_back(buffer);
	}
	// reference c++ 11.0 update for each and auto 
	// split file data and store it in a vector
	for each(string buffer in readline) {
		vector<string> splitData = split(buffer, ',');
		// split line(buffer) into (,) unit
		if (splitData[0] == "Weapon") {
			Weapon* w = new Weapon(splitData[1], splitData[2], stoi(splitData[3]), stoi(splitData[4]), stoi(splitData[5]));
			item.push_back(w);
			// store Weapon class to Item class vector 
		}
		if (splitData[0] == "Armor") {
			Armor* a = new Armor(splitData[1], splitData[2], stoi(splitData[3]), stoi(splitData[4]), stoi(splitData[5]));
			item.push_back(a);
		}
		if (splitData[0] == "Potion") {
			Potion* p = new Potion(splitData[1], splitData[2], stoi(splitData[3]), stoi(splitData[4]), splitData[5], stoi(splitData[6]));
			item.push_back(p);
		}
	}
}

void Shop::ShowItemList()
{
	int command;

	while (1) {
		cout << "Welcome to " << shop_name << "Shop! " << endl;
		cout << "------------------------------- " << endl;
		cout << "1. Show Item List " << endl;
		cout << "2. Exit" << endl;
		cout << "Select : ";

		cin >> command;
		cout << endl;
		if (command == 1) {
			cout << endl;
			cout << "-------- Item List ---------" << endl;
			for each(auto list in item) {
				list->Describe();
				cout << endl;
			}
		}
		else if (command == 2)
			return;
		else;
	}
}




