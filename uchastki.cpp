// uchastki.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;


int main(int argc, char* argv[])
{
	int N;
	cin >> N;
	while (N != 666) {
		vector<int> areas;

		for (int i = 1; i <= N; i++) {
			if (N % i == 0) {
				areas.push_back(i * (N / i));
			}
		}

		//ofstream out("output.txt");
		cout << areas.size() << endl;

		for (int area : areas) {
			cout << area << " ";
		}
		cout << endl;
		cin >> N;
	}

    return 0;
}