#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef long long s;
int boxes[1001][1001] = { 0, };

int main()
{
	ifstream in("input.txt");
	int L;
	int T;
	in >> T;
	while (T--) {
		int row;
		int col;
		in >> row;
		in >> col;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				in >> boxes[i][j];
			}
		}
		int side_max[1001] = { 0, };
		int side_max_locate[1001] = { 0, };
		int front_max[1001] = { 0, };
		int front_max_locate[1001] = { 0, };
		for (int i = 0; i < row; i++) {
			side_max[i] = boxes[i][0];
			front_max[i] = boxes[0][i];
			for (int j = 0; j < col; j++) {
				if (boxes[i][j] > side_max[i]) {
					side_max[i] = boxes[i][j];
					side_max_locate[i] = j;
				}
			}
		}
		for (int i = 0; i < col; i++) {
			front_max[i] = boxes[0][i];
			for (int j = 0; j < row; j++) {
				if (boxes[j][i] > front_max[i]) {
					front_max[i] = boxes[j][i];
					front_max_locate[i] = j;
				}
			}
		}
		s num = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (j == side_max_locate[i] || i == front_max_locate[j]) {
					continue;
				}
				else {
					num += (s)boxes[i][j];
				}
			}
		}
		cout << num << endl;
	}
}


