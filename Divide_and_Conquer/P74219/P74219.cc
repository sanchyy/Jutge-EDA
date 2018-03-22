#include <iostream>
#include <vector>
using namespace std;

bool read(mat,size) {
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			cin >> mat[i][j];
	return true;
}

int main() {
	
	vector <vector <int> > mat(vector <int> (2));
	int size = 2;
	while  (read(mat,2)) {
		int n,m; cin >> n >> m;
		
	}
	
	
}
