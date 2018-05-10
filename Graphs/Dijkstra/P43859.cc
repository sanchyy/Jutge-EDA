#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using P = pair <int,int>;
using VE = vector <P>;
using VVE = vector <VE>;

VVE G;

int n,m;

int main() {
    int u,v,c;
    while (cin >> n >> m) {
        G = VVE (n);
        cin >> u >> v >> c;
        G[u].push_back({v,c});
    }
}
