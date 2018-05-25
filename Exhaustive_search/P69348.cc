#include <iostream>
#include <vector>
using namespace std;

void f(int n,int k, vector <int> &v,vector<bool> &b) {
    if (k == n) {
	cout << '(';
	for (int i = 0; i < n; ++i)
	    cout << (i ? "," : "") << v[i];
	cout << ')' << endl;
    }
    else {

        for (int i = 1; i <= n; ++i) {
	    if (!b[i-1]){
		v[k] = i; b[i-1] = true; f(n,k+1,v,b);
		b[i-1]=false;
	    }
	}
   }
}

int main() {
    int n; cin >> n;
    vector <int> v(n);
    vector <bool>visited(n,false);
    f(n,0,v,visited);
}
