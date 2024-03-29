#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
using pairInt_t = std::pair<int, int>;

int GetTurnType(pairInt_t p1, pairInt_t p2, pairInt_t p3) {
	int turn = (p2.first - p1.first) * (p3.second - p2.second) - (p2.second - p1.second) * (p3.first - p2.first);
	if (turn > 0) {
		return 1;
	}
	else if (turn < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Not enough arguments" << std::endl;
		return 1;
	}

	std::ifstream in(argv[1]);
	if (!in) {
		std::cerr << "Can't open file" << std::endl;
		return 1;
	}

	int n;
	in >> n;

	std::vector<pairInt_t> vertices(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		in >> x >> y;
		vertices[i] = std::make_pair(x, y);
	}

	int left_turns = 0;
	int right_turns = 0;
	for (int i = 1; i < n - 1; i++) {
		int turn = GetTurnType(vertices[i - 1], vertices[i], vertices[i + 1]);
		if (turn == 1) {
			left_turns++;
		}
		else if (turn == -1) {
			right_turns++;
		}
	}

	std::cout << left_turns << " " << right_turns << std::endl;
	return 0;
}

