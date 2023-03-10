#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 100;

int M, N, field[MAXN][MAXN];
int dp[MAXN][MAXN];
int prv[MAXN][MAXN];

int main(int argc, char** argv)
{
	if (argc < 2) {
		cout << "Input valid arguments" << endl;
	}
	ifstream fin(argv[1]);
	ofstream fout("output.txt");

	fin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			fin >> field[i][j];
		}
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = field[0][0];

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (i > 0 && dp[i - 1][j] + field[i][j] < dp[i][j]) {
				dp[i][j] = dp[i - 1][j] + field[i][j];
				prv[i][j] = 1;
			}
			if (j > 0 && dp[i][j - 1] + field[i][j] < dp[i][j]) {
				dp[i][j] = dp[i][j - 1] + field[i][j];
				prv[i][j] = 2;
			}
		}
	}

	fout << dp[M - 1][N - 1] << endl;

	int i = M - 1, j = N - 1;
	vector<pair<int, int>> path;
	path.push_back(make_pair(i + 1, j + 1));
	while (i > 0 || j > 0) {
		if (prv[i][j] == 1) {
			i--;
		}
		else {
			j--;
		}
		path.push_back(make_pair(i + 1, j + 1));
	}
	reverse(path.begin(), path.end());

	for (auto p : path) {
		fout << p.first << " " << p.second << endl;
	}

	fin.close();
	fout.close();

    return 0;
}

