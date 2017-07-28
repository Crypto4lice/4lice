#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void main() {
	int max_line;		// field size var
	int player = 0;		// count player var
	int squirrel = 0;	// count squirrel var
	int rand_row;		// squirrel point x 
	int rand_col;		// squirrel point y
	string buf;			// read line
	srand((unsigned int)time(NULL));	// set squirrel point x,y as random seed = time
	vector<vector <char>> line;			// field data
	cin >> max_line;
	line.assign(max_line, vector<char>(max_line, ' '));	// set the field size and initialize
	// set field data
	for (int i = 0; i < max_line; i++) {
		cin >> buf;
		for (int j = 0; j < max_line; j++) {
			line[i][j] = buf[j];	
			if (line[i][j] == 'C')
				player++;
		}
		cout << endl;
	}

	
	cout << "----------------" << endl;
	// make a squirrel 
	while (squirrel < 2 * player) {
		// set squirrel position random
		rand_row = rand() % 5;	
		rand_col = rand() % 5;
		// if player already exist set another position
		if (line[rand_row][rand_col] == 'C')
			continue;
		// if player does not exist that position spawn squirrel
		if (line[rand_row][rand_col] == '.') {
			line[rand_row][rand_col] = 'D';
			squirrel++;
		}
	}
	// print refreshed field
	for each (auto var in line) {
		for each(auto var2 in var) {
			cout << var2;
		}
		cout << endl << endl;
	}
	
}

