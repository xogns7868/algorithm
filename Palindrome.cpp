#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int byte_arr[10] = { 0, };
bool palindromic(int t, int n) {
	int  i = 0;
	while (t > 0) {
		byte_arr[i] = t % n;
		t = t / n;
		i++;
	}
	for (int k = 0; k < i; k++) {
		if (byte_arr[k] != byte_arr[i - k - 1]) {
			return false;
		}
		
	}
	return true;
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
		int judge = 0;
		for (int i = 2; i <= 64; i++) {
			if (palindromic(a, i)) {
				judge = 1;
				break; 
			}
		}
		cout << judge << endl;
	}
}


