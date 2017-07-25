#include "Item.h"
#include <iostream>
using std::cout;
using std::endl;

Item::Item() : name(" "), description(" "),
	weight(0), value(0)
{

}

Item::Item(string _name, string _description, int _weight, int _value) 
	: name(_name), description(_description), weight(_weight), value(_value)
{
}

void Item::Describe()
{
	cout << "name        : " << name << endl;
	cout << "description : " << description << endl;
	cout << "weight      : " << weight << " lbs" << endl;
	cout << "value       : " << value << " coin" << endl;
}


