#pragma once
#include "Item.h"

class Weapon : public Item {
public:
	Weapon();
	Weapon(string name, string description, int weight, int value, int damage);
	void Describe();
private:
	int damage;
};