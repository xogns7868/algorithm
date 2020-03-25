#include <fstream>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std; 
bool chk[800001] = { 0, };
int N;
int A[10003] = { 0, };

int main() {
	ifstream in("input.txt");
	int T;
	in >> T;
	while (T--) {
		in >> N;
		for (int i = 0; i < N; i++) {
			in >> A[i];
		}
		sort(A, A + N);
		int max[4] = { 0, };
		max[0] = A[N - 1] * A[N - 2] * A[N - 3];
		max[1] = A[N - 1] * A[N - 2];
		max[2] = A[0] * A[1] * A[N - 1];
		max[3] = A[0] * A[1];
		sort(max, max + 4);
		cout << max[3] << endl;
	}
}