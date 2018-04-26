#include <iostream>
#include <vector>
using namespace std;

int n,m;

bool dfs(vector <vector<char> > &tmap, int x, int y) {
	if (x >= 0 and x < n and y >= 0 and y < m or tmap[x][y] == 'X') {
		if (tmap[x][y] == 't') return true;
		tmap[x][y] = 'X';
		return (
			dfs(tmap,x+1,y) || 
			dfs(tmap,x-1,y) ||
			dfs(tmap,x,y+1) ||
			dfs(tmap,x,y-1));
	}
	return false;
}

int main() {

	cin >> n >> m;
	vector <vector <char> > treasure_map(n,vector<char>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> treasure_map[i][j];
	int x,y; cin >> x >> y;
	cout << (dfs(treasure_map, x-1,y-1) ? "yes" : "no") << endl;
}
