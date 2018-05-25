#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;

void f(int k, vector<int> &v) {
    if (k == n) {
        for (int i = 0; i < n; ++i)
            cout << (i ? " " : "") << v[i];
        cout << endl;
    }
    else {
        v[k] = 0; f(k+1,v);
        v[k] = 1; f(k+1,v);
    }

}

int main() {
    cin >> n;
    vector <int> v(n);
    f(0,v);
}
