#include <iostream>
#include <vector>
using namespace std;

int n,m;
using Graph = vector <vector <char> >;
Graph tmap;

int dfs(int x, int y) {
	if (x >= 0 and x < n and y >= 0 and y < m) {
		if (tmap[x][y] == 'X') return 0;
		bool treasure = tmap[x][y] == 't';
		tmap[x][y] = 'X';
		int result = (
			dfs(x+1,y) + 
			dfs(x-1,y) +
			dfs(x,y+1) + 
			dfs(x,y-1)
			);
		return result + treasure;
	}
	return 0;
}

int main() {

	cin >> n >> m;
	tmap = Graph(n,vector<char>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> tmap[i][j];
	int x,y; cin >> x >> y;
	cout << dfs(x-1,y-1) << endl;
}
