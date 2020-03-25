#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool judge_prime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
}
int main()
{
	ifstream in("input.txt");
	int L;
	int T;
	in >> T;
	while (T--) {
		int a;
		in >> a;
		int difference[1001] = { 0, };
		int first[1001] = { 0, };
		int second[1001] = { 0, };
		int count = 0;
		for (int i = 2; i < a; i++) {
			if (judge_prime(i) && judge_prime(a - i) && (a - i) > 1 && i <= a-i) {
				first[count] = i;
				second[count] = a - i;
				difference[count] = second[count] - first[count];
				count++;
			}
		}
		if (count > 1) {
			int min = difference[0];
			int idx = 0;
			for (int i = 0; i < count; i++) {
				if (min > difference[i]) {
					min = difference[i];
					idx = i;
				}
			}
			cout << first[idx] << " " << second[idx] << endl;
		}
		else {
			cout << first[0] << " " << second[0] << endl;
		}
	}
}


