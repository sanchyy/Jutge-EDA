#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;


int n,m;
using P = pair <int,int>;
using VC = vector <char>;
using VVC = vector <VC>;
using VE = vector <int>;
using VVE = vector <VE>;

VVC G;
VVE dist;

bool tresor(int x, int y, queue<P> &Q, int d) {
	if (x < 0 or x >= n or y < 0 or y >= m or G[x][y] == 'X' or dist[x][y] != -1) return false;
	if (G[x][y] == 't') return true;
	dist[x][y] = d;
	Q.push(P(x,y));
	return false;
}

void solu(int i, int j) {
	dist = VVE(n, VE(m,-1));
	queue<P> Q;
	Q.push(P(i,j));
	dist[i][j] = 0;
	while (not Q.empty()) {
		P v = Q.front();
		Q.pop();
		int x = v.first;
		int y = v.second;
		int d = dist[x][y]+1;
		if (tresor(x,y+1,Q,d) or tresor(x,y-1,Q,d) or tresor(x+1,y,Q,d) or tresor(x-1,y,Q,d)) {
			cout << "minimum distance: " << d << endl;
			return;
		}

	}
	cout << "no treasure can be reached" << endl;
}

int main () {
	cin >> n >> m;
	G = VVC(n, VC(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> G[i][j];
	int f,c; cin >> f >> c;
	solu(f-1,c-1);
	
	
	
}
