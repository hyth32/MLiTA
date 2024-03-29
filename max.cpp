#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> segTree;
std::vector<int> arr;

void buildTree(int node, int start, int end) {
	if (start == end) {
		segTree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	buildTree(2 * node, start, mid);
	buildTree(2 * node + 1, mid + 1, end);
	segTree[node] = std::max(segTree[2 * node], segTree[2 * node + 1]);

}

int queryMax(int node, int start, int end, int left, int right) {
	if (start > right || end < left) {
		return INT_MIN;
	}
	if (start >= left && end <= right) {
		return segTree[node];
	}

	int mid = (start + end) / 2;
	int maxLeft = queryMax(2 * node, start, mid, left, right);
	int maxRight = queryMax(2 * node + 1, mid + 1, end, left, right);

	return std::max(maxLeft, maxRight);
}

void update(int node, int start, int end, int idx, int value) {
	if (start == end) {
		arr[idx] = value;
		segTree[node] = value;
		return;
	}

	int mid = (start + end) / 2;
	if (idx <= mid) {
		update(2 * node, start, mid, idx, value);
	}
	else {
		update(2 * node + 1, mid + 1, end, idx, value);
	}
	segTree[node] = std::max(segTree[2 * node], segTree[2 * node + 1]);
}

void add1(int idx, int delta) {
	update(1, 0, arr.size() - 1, idx, arr[idx] + delta);
}

void add2(int left, int right, int delta) {
	for (int i = left; i <= right; i++) {
		add1(i, delta);
	}
}

void printArray() {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "Invalid parameters" << std::endl;
		return 1;
	}
	std::ifstream in(argv[1]);

	int value;
	while (in >> value) {
		arr.push_back(value);
	}

	int n = arr.size();
	segTree.resize(4 * n);

	buildTree(1, 0, n - 1);

	std::string action;
	int i, j, d;
	while (true) {
		std::cin >> action;

		if (action == "Out") {
			printArray();
		}
		else if (action == "Rmq") {
			std::cin >> i >> j;
			std::cout << queryMax(1, 1, n, i, j) << std::endl;
		}
		else if (action == "Add1") {
			std::cin >> i >> d;
			add1(i - 1, d);
		}
		else if (action == "Add2") {
			std::cin >> i >> j >> d;
			add2(i - 1, j - 1, d);
		}
		else if (action == "Exit") {
			break;
		}
		else {
			std::cout << "Invalid action" << std::endl;
		}
	}

    return 0;
}

