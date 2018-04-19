#include <iostream>
#include <vector>
using namespace std;

int n,m;

int dfs(vector <vector<char> > &tmap, int x, int y) {
	if (x >= 0 and x < n and y >= 0 and y < m) {
		if (tmap[x][y] == 'X') return 0;
		bool treasure = tmap[x][y] == 't';
		tmap[x][y] = 'X';
		int result = (
			dfs(tmap,x+1,y) + 
			dfs(tmap,x-1,y) +
			dfs(tmap,x,y+1) + 
			dfs(tmap,x,y-1));
		return result + treasure;
	}
	return 0;
}

int main() {

	cin >> n >> m;
	vector <vector <char> > treasure_map(n,vector<char>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> treasure_map[i][j];
	int x,y; cin >> x >> y;
	cout << dfs(treasure_map, x-1,y-1) << endl;
}