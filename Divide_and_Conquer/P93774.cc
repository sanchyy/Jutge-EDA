#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n,m;
	while (cin >> n >> m) {
		vector <vector <char> > P(n, vector <char> (m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> P[i][j];
		
	}
}