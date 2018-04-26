#include <iostream>
#include <vector>
using namespace std;

int n,m;
using VC = vector <char>;
using VVC = vector <VC>;

VVC tmap;

bool dfs(int x, int y) {
	if (x < 0 or x >= n or y < 0 or y >= m or tmap[x][y] == 'X') return false;
	if (tmap[x][y] == 't') return true;
	tmap[x][y] = 'X';
	return (
		dfs(x+1,y) || 
		dfs(x-1,y) ||
		dfs(x,y+1) ||
		dfs(x,y-1));
	}

int main() {

	cin >> n >> m;
	tmap = VVC(n,VC(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> tmap[i][j];
	int x,y; cin >> x >> y;
	cout << (dfs(x-1,y-1) ? "yes" : "no") << endl;
}
