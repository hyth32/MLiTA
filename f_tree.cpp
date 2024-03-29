#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void update(std::vector<int>&tree, int i, int delta) {
	while (i < tree.size()) {
		tree[i] += delta;
		i += i & -i;
	}
}

int rsq(const std::vector<int>&tree, int i) {
	int sum = 0;
	while (i > 0) {
		sum += tree[i];
		i -= i & -i;
	}
	return sum;
}

int rsq(const std::vector<int>&tree, int i, int j) {
	return rsq(tree, j) - rsq(tree, i - 1);
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "Invalid parameters" << std::endl;
		return 1;
	}

	std::ifstream in(argv[1]);

	int n;
	in >> n;

	std::vector<int> tree(n + 1);
	std::vector<int> array(n + 1);

	for (int i = 0; i < n; i++) {
		in >> array[i];
		update(tree, i + 1, array[i]);
	}

	std::string command;
	while (std::cin >> command) {
		if (command == "Out") {
			for (int i = 0; i < n; i++) {
				std::cout << array[i] << ' ';
			}
			std::cout << std::endl;
		}
		else if (command == "Rsq") {
			int i, j;
			std::cin >> i >> j;
			std::cout << rsq(tree, i + 1, j + 1) << std::endl;
		}
		else if (command == "Add") {
			int i, v;
			std::cin >> i >> v;
			array[i] += v;
			update(tree, i + 1, v);
		}
		else if (command == "Update") {
			int i, v;
			std::cin >> i >> v;
			update(tree, i + 1, v - array[i]);
			array[i] = v;
		}
		else if (command == "Exit") {
			break;
		}
		else {
			std::cout << "Unknown command" << std::endl;
		}
	}

    return 0;
}

