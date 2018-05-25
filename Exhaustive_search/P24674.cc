#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int n;

void f(int k, vector <string> &v, vector <bool> &s, const vector <string> &ve) {
    if (k == n) {
        cout << '(';
        for (int i = 0 ; i < n; ++i)
            cout << (i ? "," : "") << v[i];
        cout << ')' << endl;
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (!s[i]) {
                s[i] = true;
                v[k] = ve[i];
                f(k+1,v,s,ve);
                s[i] = false;
            }
        }
    }
}

int main() {
    cin >> n;
    vector <string> ve(n);
    for (int i = 0; i < n; ++i)
        cin >> ve[i];
    vector <string> v(n);
    vector <bool> s(n,false);
    f(0,v,s,ve);
}
