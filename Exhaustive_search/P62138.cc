#include <iostream>
#include <vector>
using namespace std;


int n;
vector <string> v;
vector <bool> b;

void f(int k, int ns) {
    if (k == n) {
        for (int i = 0; i < ns; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << "subset " << i << ": {";
                cout << (j ? "," : "") << v[i];
            }
            cout << endl;
        }
    }
    else {

    }
}

int main() {
    cin >> n;
    v = vector <string> (n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    b = vector <bool> (n);
    int n_s; cin >> n_s;
    f(0,n_s);

}
