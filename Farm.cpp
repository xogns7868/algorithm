#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	ifstream in("input.txt");
	int L;
	int T;
	in >> T;
	while (T--) {
		int a, b, n, w;
		in >> a;
		in >> b;
		in >> n;
		in >> w;
		int x = -1;
		int y = -1;
		int count = 0;
		for (int i = 1; i < n; i++) {
			if ((n - i) * a + i * b == w) {
				x = n - i;
				y = i;
				count++;
			}
		}
		if (count > 1 || count == 0) {
			cout << -1 << endl;
		}
		else {
			cout << x << " " << y << endl;
		}
	}
}


