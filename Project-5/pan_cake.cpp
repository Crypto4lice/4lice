#include <iostream>
#include <string>
using namespace std;

void main() {
	string str;
	int flag = 0;	// when print each process, avoid overlap
	int count = 0;	// try count
	cin >> str;
	/* start = last index =>  [0] [1] [2] <--------- [last_index]
									   end point */
	for (int i = str.length() - 1; i >= 2; i--) {
		// if the face is back side
		if (str[i] == '-') {
			// turn 
			str[i] = '+';
			// we must turn set of three data, then turn next two data
			if (str[i - 1] == '+')
				str[i - 1] = '-';
			else if (str[i - 1] == '-')
				str[i - 1] = '+';

			if (str[i - 2] == '+')
				str[i - 2] = '-';
			else if (str[i - 2] == '-')
				str[i - 2] = '+';

			count++;
			flag = 1;
		}
		if (flag == 1) {
			cout << count << " : " << str << endl;
			flag = 0;
		}
	}
	// if all side is not front -> you can't make
	for (auto var : str) {
		if (var == '-') {
			cout << "You Can't make it" << endl;
			return;
		}
	}
	cout << "You Can Make It " << count << " try!" << endl;
}