#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,s;
bool sol;
bool kompare(int a, int b){
    return a > b;
}
void f(int k, int sum, vector <int> &v,  vector <bool> &b) {
    if (k == s && sum != n)  return;
    if (k == s && sum == n) {
        cout << '{';
        bool first = true;
        sol = true;
        for (int i = 0; i < s; ++i) {
            if (b[i]) {
                if (first) first = !first;
                else cout << ',';
                cout << v[i];
            }
        }
        cout << '}' << endl;
        return;
    }
    else {
        b[k] = true;
        f(k+1,sum+v[k],v,b); //recursiva
        if (sol) return;
        b[k] = false; //marco com a visitat
        f(k+1,sum,v,b); //tornarà a cridar la funcio

    }
}


int main() {
    cin >> n >> s;
    vector <int> v(s);
    for (int i = 0; i < s; ++i)
        cin >> v[i];
    vector <bool> b(s,false);
    sort(v.begin(),v.end(),kompare);
    sol = false;
    f(0,0,v,b); //f(k,suma,v,b)
    if (!sol) cout << "no solution" << endl;
}
