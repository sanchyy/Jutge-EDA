#include <iostream>
#include <vector>
using namespace std;

using VE = vector <int>;
using VVE = vector <VE>;

int n,m;
VVE G;
 
int main() {
	while (cin >> n >> m) {
		G = VVE (n, VE(m));
	}
}
