#include <iostream>
#include <vector>
#include <utility>
using namespace std;

using VB = vector <bool>;
using VC = vector <char>;
using VVC = vector <VC>;

int n,m;
VB visit;
VVC G;

void DFS(int x, int y, char c) {
    if (x >= 0 and x < n and y >= 0 and y < m) {
        if (G[x][y] == '#')
            return;
        G[x][y] = c;
        DFS(x+1,y,c);
        DFS(x-1,y,c);
        DFS(x,y+1,c);
        DFS(x,y-1,c);
    }
}

void solu() {
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) {
            if ((G[i][j] != '#' and G[i][j] != '.'))
                DFS(i,j,G[i][j]);
        }
    }
}

int main() {
    while (cin >> n >> m) {
        G = VVC(n,VC(m));
        visit = VB(n,false);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> G[i][j];

        solu();

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j)
                cout << G[i][j];
            cout << endl;
        }
    }
}
