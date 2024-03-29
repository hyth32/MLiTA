#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "Not valid size of parameters";
		return 1;
	}

	std::ifstream in(argv[1]); 
	if (!in.is_open()) {
		std::cout << "Error opening input file";
		return 1;
	}

	int k;
	in >> k;

	std::vector<std::vector<int>> graph(k + 1);
	std::vector<int> indegrees(k + 1);
	for (int i = 1; i <= k; i++) {
		int j;
		in >> j;
		while (j--) {
			int x;
			in >> x;
			graph[x].push_back(i);
			indegrees[i]++;
		}
	}
	in.close();

	std::queue<int> q;
	for (int i = 1; i <= k; i++) {
		if (indegrees[i] == 0) {
			q.push(i);
		}
	}

	std::vector<int> order;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		order.push_back(u);
		for (int v : graph[u]) {
			if (--indegrees[v] == 0) {
				q.push(v);
			}
		}
	}

	if (order.size() != k) {
		std::cout << "NO" << std::endl;
	}
	else {
		std::cout << "YES" << std::endl;
		for (int i : order) {
			std::cout << i << std::endl;
		}
	}

    return 0;
}

