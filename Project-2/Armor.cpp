#include "Armor.h"
#include "Item.h"
#include <iostream>
using std::cout;
using std::endl;

Armor::Armor() : Item(), defense(0)
{
}

Armor::Armor(string name, string description, int weight, int value, int defense)
	: Item(name, description, weight, value), defense(defense)
{
}

void Armor::Describe()
{
	Item::Describe();
	cout << "defense     : " << defense << endl;
}

