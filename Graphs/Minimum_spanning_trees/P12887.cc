#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using P   = pair <int,int>;
using VP  = vector <P>;
using VVP = vector <VP>;
using VB  = vector <bool>;


int n,m;
VVP G;
VB vis;

void MST() {
    vis = VB(n,false);
    priority_queue <P, VP, greater<P>> Q;
    Q.push({0,0});
    int sum = 0;

    while (!Q.empty()) {
        int weight = Q.top().first;
        int vertex = Q.top().second;
        Q.pop();
        if (!vis[vertex]) {
            vis[vertex] = true;
            sum += weight;
            for (P p : G[vertex]) {
                int next_w = p.first;
                int next_v = p.second;
                Q.push({next_w,next_v});

            }
        }
    }
    cout << sum << endl;
}

int main() {
    while (cin >> n >> m) {
        G = VVP(n);
        for (int i = 0; i < m; ++i) {
            int u,v,w;
            cin >> u >> v >> w;
            G[u-1].push_back({w,v-1});
            G[v-1].push_back({w,u-1});
        }
        MST();
    }
}
