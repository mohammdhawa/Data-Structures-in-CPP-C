#include <iostream>
#include <queue>
#include <stack>

void DFS_usingRecursion(int u, int A[][7], int n) {
	static int visited[8]{ 0 };
	
	if (visited[u] == 0) {
		std::cout << u << ", ";
		visited[u] = 1;
		for (int v = 1; v < n; v++) {
			if (A[u][v] == 1 && visited[v] == 0)
				DFS_usingRecursion(v, A, n);
		}
	}
}

void DFS(int u, int A[][7], int n) {
	int visited[8]{ 0 };
	std::stack<int>stk;
	stk.emplace(u);

	std::cout << u << ", ";
	visited[u] = 1;

	int v = 0;

	while (!stk.empty()) {
		while (v < n) {
			if (A[u][v] == 1 && visited[v] == 0) {
				stk.push(u);
				u = v;
				
				std::cout << u << ", ";
				visited[u] = 1;
				v = -1;
			}
			v++;
		}
		v = u;
		u = stk.top();
		stk.pop();
	}
}

int main()
{

	int G[7][7] = { {0,0,0,0,0,0,0},
					{0,0,1,1,0,0,0},
					{0,1,0,0,1,0,0},
					{0,1,0,0,1,0,0},
					{0,0,1,1,0,1,1},
					{0,0,0,0,1,0,0},
					{0,0,0,0,1,0,0} };

	std::cout << "DFS Vertex: 4 -> ";
	DFS_usingRecursion(4, G, 7);
	std::cout << std::endl;

	std::cout << "DFS Vertex: 4 -> ";
	DFS(4, G, 8);
	std::cout << std::endl;




	return 0;
}
