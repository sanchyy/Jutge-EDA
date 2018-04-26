#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector<char> > Graph;
int n,m;
Graph graph;

int BFS(int i, int j) {
	
}

int main () {
	cin >> n >> m;
	graph = Graph(n, vector <char> (m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> graph[i][j];
	
	int f,c; cin >> f >> c;
	
}
