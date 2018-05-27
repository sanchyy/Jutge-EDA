#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using P   = pair   <int,int>;
using VP  = vector <P>;
using VVP = vector <VP>;
using VE  = vector <int>;
using VVE = vector <VE>;

VVP G;
VE cost;

int n,m;
int x,y;
const int MAX = 1e9;

void Dijkstra() {

    cost = VE(n,MAX);
    cost[x] = 0;
    priority_queue <P, VP, greater<P>> Q;
    Q.push({0,x});

    while(!Q.empty()){
        int weight = Q.top().first;
        int vertex = Q.top().second;
        Q.pop();

        if (vertex  == y) return;
        for (int i = 0; i < (int)G[vertex].size(); ++i) {
            int next_w = G[vertex][i].first;
            int next_v = G[vertex][i].second;
            if (cost[next_v] > (weight + next_w)) {
                cost[next_v] =  weight + next_w;
                Q.push({cost[next_v],next_v});
            }
        }
    }
}

int main() {
    while (cin >> n >> m) {
        G = VVP (n);
        for (int i = 0; i < m; ++i) {
            int u,v,c;
            cin >> u >> v >> c;
            G[u].push_back({c,v});
        }
        //x -> inici ; y -> final
        cin >> x >> y;
        Dijkstra();

        if (cost[y] < MAX) cout << cost[y] << endl;
        else cout << "no path from " << x << " to " << y << endl;
    }
}
