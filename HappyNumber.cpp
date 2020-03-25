#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int temp[1000] = {};

int happy(int L) {
	int number = 0;
	while (L > 0) {
		number += (L % 10) * (L % 10);
		L = L / 10;
	}
	if (number == 1) {
		return 1;
	}
	for (int i = 0; i < 1000; i++) {
		if (temp[i] == -1) {
			temp[i] = number;
			break;
		}
		if (temp[i] == number) {
			return -1;
		}
	}
	return happy(number);
}
int main()
{
	ifstream in("input.txt");
	int L;
	int T;
	in >> T;
	while (T--) {
		for (int i = 0; i < 1000; i++) {
			temp[i] = -1;
		}
		in >> L;
		int k = happy(L);
		if (k == 1) {
			cout << "HAPPY" << endl;
		}
		else {
			cout << "UNHAPPY" << endl;
		}
	}
}


