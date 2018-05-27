#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <bool> vis;
vector <int> v;

void f(int x, int sum, int i) {
    if (sum == x) {
        for(int j = 0; j < 2*n; ++j)
            cout << (j ? "" : "?") << v[j] << (j%2 ? "p" : "");
        cout << endl;
    }
    else {
        for (int j = 1; j < 2*n; ++j) {
            if (sum+v[j] <= x and !vis[j]) {
                vis[j] = true;
                f(x,sum+v[j],i+1);
                vis[j] = false;
            }
        }
    }
}

int main() {
    int n_total, n;
    while(cin >> n_total) {
        cin >> n;
        vector <int> v(2*n);
        for (int i = 0; i < n; ++i){
            cin >> v[i];
            v[i+1] = v[i];
        }
        vector <bool> vis(2*n,false);
        sort(v.begin(),v.end());
        f(n,0,0);
    }
}
