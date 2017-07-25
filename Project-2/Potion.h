#pragma once
#include "Item.h"

class Potion : public Item {
public:
	Potion();
	Potion(string name, string description, int weight, int value, string type, int capacity);
	void Describe();
private:
	string type;
	int capacity;
};