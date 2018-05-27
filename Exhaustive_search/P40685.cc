#include <iostream>
#include <vector>
using namespace std;

int n,s;

void f(int k, int sum, vector <int> &v,  vector <bool> &b) {
    if (k == s && sum != n)  return;
    if (k == s && sum == n) {
        cout << '{';
        bool first = true;
        for (int i = 0; i < s; ++i) {
            if (b[i]) {
                if (first) first = !first;
                else cout << ',';
                cout << v[i];
            }
        }
        cout << '}' << endl;
    }
    else {
        f(k+1,sum,v,b); //tornarà a cridar la funcio
        b[k] = true; //marco com a visitat
        f(k+1,sum+v[k],v,b); //recursiva
        b[k] = false; //no visitat (per a la proxima rec)
    }
}


int main() {
    cin >> n >> s;
    vector <int> v(s);
    for (int i = 0; i < s; ++i)
        cin >> v[i];
    vector <bool> b(s,false);
    //sort(v.begin(),v.end());
    f(0,0,v,b); //f(k,suma,v,b)
}
