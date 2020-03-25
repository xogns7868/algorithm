#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int temp[1000] = {};
int value = -1;


int main()
{
	ifstream in("input.txt");
	int L;
	int T;
	in >> T;
	while(T--){
		int team_number, total_game;
		in >> team_number;
		in >> total_game;

		int team_score[1001] = { 0, };
		int team_minscore[1001] = { 0, };
		int team_win[1001] = { 0, };
		for (int i = 0; i < total_game; i++) {
			int a, b,p,q;
			in >> a;
			in >> b;
			in >> p;
			in >> q;
			team_score[a] += p;
			team_minscore[b] += p;
			team_minscore[a] += q;
			team_score[b] += q;
		}
		for (int i = 1; i <= team_number; i++) {
			float S = team_score[i] * team_score[i];
			float A = team_minscore[i] * team_minscore[i];
			if (S == 0 && A == 0) {
				team_win[i] = 0;
			}
			else {
				team_win[i] = (S / (S + A)) * 1000;
			}
		}
		int max = team_win[1];
		int min = team_win[1];
		for (int i = 1;  i <= team_number; i++) {
			if (team_win[i] > max) {
				max = team_win[i];
			}
			if (team_win[i] < min) {
				min = team_win[i];
			}
		}
		cout << max << endl;
		cout << min << endl;

	}
}


