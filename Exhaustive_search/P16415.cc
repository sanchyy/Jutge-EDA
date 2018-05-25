#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> c;
vector<bool> col, diag1, diag2;

int f(int k) {
  if (k == n) return 1;
  else {
    int m = 0;
    for (int i = 0; i < n; ++i) {
      if (not col[i]     and
	  not diag1[n-1+i-k] and
	  not diag2[i+k]) {
	col[i] = true;
	diag1[n-1+i-k] = true;
	diag2[i+k] = true;
	c[k] = i;
	m += f(k+1);
	col[i] = false;
	diag1[n-1+i-k] = false;
	diag2[i+k] = false;
      }
    }
    return m;
  }
}

int main() {
  cin >> n;
  c = vector<int>(n);
  col   = vector<bool>(n,     false);
  diag1 = vector<bool>(2*n-1, false);
  diag2 = vector<bool>(2*n-1, false);
  cout << f(0) << endl;
}
