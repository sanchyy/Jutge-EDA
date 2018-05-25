#include <iostream>
#include <vector>
using namespace std;

int n;

vector <char> cons;
vector <char> vow;

void f (int k, vector<bool> &cons_b, vector <bool> &vow_b,vector <char> &v) {
    if (k == 2*n) {
        for (int i = 0; i < 2*n; ++i)
            cout << v[i];
        cout << endl;
    }

    else {
        if (k%2) //vowels
            for (int i = 0; i < n; ++i) {
                if (!vow_b[i]) {
                    vow_b[i] = true;
                    v[k] = vow[i];
                    f(k+1,cons_b,vow_b,v);
                    vow_b[i] = false;
                }
            }
        else
            for (int i = 0; i < n; ++i) {
                if (!cons_b[i]) {
                    cons_b[i] = true;
                    v[k] = cons[i];
                    f(k+1,cons_b,vow_b,v);
                    cons_b[i] = false;
                }
            }
    }
}

int main() {
    cin >> n;
    cons = vector <char> (n);
    vow  = vector <char> (n);
    for (int i = 0; i < n; ++i)
        cin >> cons[i];
    for (int i = 0; i < n; ++i)
        cin >> vow[i];
    vector <bool> cons_b (n,false);
    vector <bool> vow_b  (n, false);
    vector <char> v(2*n);
    f(0,cons_b,vow_b,v);
}
