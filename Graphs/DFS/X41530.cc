#include <iostream>
#include <vector>
using namespace std;
 

using Graph =  vector< vector <int> >;

void escriure_graf(const Graph& g) {
    for (int i = 0; i < g.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < g[i].size(); j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}
 
void cerca_cicles(const Graph& g, vector<bool>& visited, int i, int pare, bool& b) {
    if (!visited[i]) {
        visited[i] = true;
        for (int j = 0; j < g[i].size(); j++) {
            if (g[i][j] != pare) //no s'ha d'operar si el vèrtex és el seu pare ja que detectariem un cicle fals
                cerca_cicles(g, visited, g[i][j], i, b);
                if (b) return;
        }
    }
    else b = true;
}
 
void dfs(const Graph& g) {
    vector<bool> vis(g.size(), false);
    int na = 0; //#arbres
    for (int i = 0; i < g.size(); i++) {
        if (!vis[i]) {
            bool b = false;
            cerca_cicles(g, vis, i, i, b);
            if (b) {
                cout << "no" << endl;
                return; //si es troba algun cicle no cal operar més
            }
            else na++;
        }
    }
    cout << na << endl;
}
 
int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph g(n);
        for (int j = 0; j < m; j++) {
        int x,y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
        dfs(g);
    }
}
