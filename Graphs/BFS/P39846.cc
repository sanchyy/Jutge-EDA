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

void BFS(int x, int y, queue <P> &Q, int d) {
	if ((x >= 0 and x < n) and (y >= 0 and y < m) and (G[x][y] == '.' or G[x][y] == 't')) {
		Q.push(P(x,y));
		dist[x][y] = d+1;
	}
}

void solu(int f, int c) {
	dist = VVE(n,VE(m,-1));
	dist[f][c] = 0;
	queue <P> Q;
	Q.push(P(f,c));
	int d = 0;
	while (not Q.empty()) {
		P v = Q.front();
		Q.pop();
		int x = v.first;
		int y = v.second;

		if (G[x][y] == 't' and d < dist[x][y])
			d = dist[x][y];
		if (G[x][y] == '.' or G[x][y] == 't') {
			G[x][y] = 'X';
			BFS(x+1,y,Q,dist[x][y]);
			BFS(x-1,y,Q,dist[x][y]);
			BFS(x,y+1,Q,dist[x][y]);
			BFS(x,y-1,Q,dist[x][y]);
		}
	}
 	if (!d)
		cout << "no treasure can be reached" << endl;
	else
		cout << "maximum distance: " << d << endl;
}

int main() {
	cin >> n >> m;
	G = VVC(n,VC(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> G[i][j];

	int f,c; cin >> f >> c;
	solu(f-1,c-1);
}
