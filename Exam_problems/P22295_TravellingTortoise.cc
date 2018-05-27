#include <iostream>
#include <vector>
using namespace std;

using VB  = vector <bool>;
using VVB = vector <VB>;

using VC  = vector <char>;
using VVC = vector <VC>;

using VE  = vector <int>;
using VVE = vector <VE>;

int n,m;
int xi,xj,yi,yj;
VVC M;
VVB b;

const int I[4] = {0, -1,  0, 1};
const int J[4] = {1,  0, -1, 0};

bool pos_ok(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void f(int ai, int aj, vector <char> &v) {

    if (ai == yi && aj == yj) {
        for (int i = 0; i < (int)v.size(); ++i)
            cout << v[i];
        cout << endl;
    }
    else {
        for (int i = 0; i < 4; ++i) {
            int new_i = ai + I[i];
            int new_j = aj + J[i];
            if (pos_ok(new_i,new_j) && !b[new_i][new_j]) {
                b[new_i][new_j] = true;
                v.push_back(M[new_i][new_j]);
                f(new_i, new_j, v);
                v.pop_back();
                b[new_i][new_j] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    M = VVC(n,VC(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> M[i][j];
    cin >> xi >> xj >> yi >> yj;
    VC v;
    b = VVB(n, VB(m,false));
    b[xi][xj] = true;
    v.push_back(M[xi][xj]);
    f(xi,xj,v);
}
