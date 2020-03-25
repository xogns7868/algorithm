#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <deque>
#include <math.h>
using namespace std;


int main() {

	ifstream in("input.txt");
	int T;
	in >> T;
	while (T--) {
		int n;
		int w;
		int l;
		in >> n;
		in >> w;
		in >> l;
		queue<int> q;

		int sum, count; 
		sum = 0;
		count = 0;
		for(int i = 0; i < n; i++){
			int d;
			in >> d;
			while (true) {
				if (q.empty()) {
					q.push(d);
					count++;
					sum += d;
					break;
				}
				else if (q.size() == w) {
					sum -= q.front(); 
					q.pop();
				}
				else {
					if (sum + d > l) {
						q.push(0);
						count++;
					}
					else {
						q.push(d);
						count++;
						sum += d;
						break;
					}
				}
			}
		}

		cout << count + w << endl;
	}
}
