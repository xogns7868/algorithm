#include <fstream>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int num[1000000];
int main() {
	int t;
	ifstream input("input.txt");
	input >> t;
	while (t--) {
		int n, k,i;
		int a = 0;
		int cnt = 0;
		int min_ = 999999999;
		input >> n >> k;
		int b = n - 1;
		for (i = 0; i < n; i++) input >> num[i];
		sort(num, num + n);
		while (a < b) {
			int tmp = k - (num[a] + num[b]);
			if (min_ > abs(tmp)) {
				min_ = abs(tmp);
				cnt = 0;
			}
			if (min_ == abs(tmp)) {
				cnt++;
			}
			if (tmp > 0) a++;
			else if (tmp < 0) b--;
			else {
				a++;
				b--;
			}
		}
		cout << cnt << endl;
		memset(num, 0, sizeof(int) * 100000);
	}
	
}