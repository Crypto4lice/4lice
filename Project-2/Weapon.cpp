#include "Weapon.h"
#include <iostream>
using std::cout;
using std::endl;

Weapon::Weapon() : Item(), damage(0)
{
}

Weapon::Weapon(string name, string description, int weight, int value, int damage)
	: Item(name, description, weight, value), damage(damage)
{
}

void Weapon::Describe()
{
	Item::Describe();
	cout << "damage      : " << damage << endl;
}
