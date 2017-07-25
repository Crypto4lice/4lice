#include "Item.h"
#include "Weapon.h"
#include "Shop.h"
#include <iostream>
#include <Windows.h>
#include <process.h>
using namespace std;

void main() {
	Shop* Weapon_shop = new Shop("Weapon Shop", "equip_item.txt");
	Shop* Armor_shop = new Shop("Armor Shop", "equip_item.txt");
	Shop* Potion_shop = new Shop("Potion Shop", "Potion_item.txt");
	int command;
	while (1) {
		cout << "--------Shop Select---------" << endl;
		cout << "1. Weapon Shop" << endl;
		cout << "2. Armor Shop" << endl;
		cout << "3. Potion Shop" << endl;
		cout << "4. Exit" << endl;
		cout << endl;
		cout << "Select : ";
		cin >> command;
		switch (command) {
		case 1:
			Weapon_shop->ShowItemList();
			break;
		case 2:
			Armor_shop->ShowItemList();
			break;
		case 3:
			Potion_shop->ShowItemList();
			break;
		case 4:
			exit(1);
		default:
			cout << "Oops wrong command" << endl;
			cout << endl;
			Sleep(1000);
			system("cls");
		}
	}
}