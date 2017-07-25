#include "Potion.h"
#include "Item.h"
#include <iostream>
using std::cout;
using std::endl;

Potion::Potion() : Item(), type(" "), capacity(0)
{
}

Potion::Potion(string name, string description, int weight, int value, string type, int capacity)
	: Item(name, description, weight, value), type(type), capacity(capacity)
{
}

void Potion::Describe()
{
	Item::Describe();
	cout << "type        : " << type << endl;
	cout << "capacity    : " << capacity << endl;
}




