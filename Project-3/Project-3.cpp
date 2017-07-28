#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void main() {
	int max_line;
	int player = 0;
	int squirrel = 0;
	int rand_row;
	int rand_col;
	string buf;
	srand((unsigned int)time(NULL));
	vector<vector <char>> line;
	cin >> max_line;
	line.assign(max_line, vector<char>(max_line, ' '));
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

	while (squirrel < 2 * player) {
		rand_row = rand() % 5;
		rand_col = rand() % 5;
		if (line[rand_row][rand_col] == 'C')
			continue;
		if (line[rand_row][rand_col] == '.') {
			line[rand_row][rand_col] = 'D';
			squirrel++;
		}
	}

	for each (auto var in line) {
		for each(auto var2 in var) {
			cout << var2;
		}
		cout << endl << endl;
	}
	
}

