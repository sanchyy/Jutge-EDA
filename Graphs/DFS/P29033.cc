#include <iostream>
#include <vector>
#include <utility>
using namespace std;

using VE = vector <int>;
using VVE = vector <VE>;

const int colors = 2;
int n,m;
VVE G;
VE visit;
VE color;

bool DFS (int x, int y, int s) {
    if (visit[x]) {
        if (color[x] == color[y]) return true;
        return false;
    }
    else {
        color[x] = s%colors;
        visit[x] = true;
        bool aux = false;
        for (int i = 0; i < int(G[x].size()) and not aux; ++i) {
            if (G[x][i] != y)
                aux = aux or DFS(G[x][i],x,s+1);
        }
        return aux;
    }
}

void solu() {
    visit = VE(n,false);
    color = VE(n,0);
    bool col = false;
    for (int i = 0; i < n and not col; ++i) {
        if (not visit[i])
            col = col or DFS(i,-1,0);
    }
    cout << (!col ? "yes" : "no") << endl;

}

int main() {
    while (cin >> n >> m) {
        G = VVE (n);
        for (int i = 0; i < m; ++i) {
            int x,y; cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        solu();
    }
}
