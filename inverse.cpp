#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool check_arguments(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <input file>" << endl;
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (!check_arguments(argc, argv)) {
		return 1;
	}

	ifstream input(argv[1]);
	int n;
	input >> n;

	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		input >> d[i];
	}
	input.close();

	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		p[i] = i + 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		int k = i;
		while (k < n - 1 && d[k] > 0) {
			swap(p[k], p[k + 1]);
			d[k]--;
			k++;
		}
	}

	//ofstream out("output.txt");
	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}
	//out.close();

	system("pause");

	return 0;
}