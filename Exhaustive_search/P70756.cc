#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<bool> VB;

VB  b;
VVS vvs;

void backtracking(int k, VS& vs){
	if (k == (int)vs.size()) {
        for (int i = 0; i < (int)vvs.size(); ++i) {
    		cout << "subset " << i+1 << ": {";
    		for (int j = 0; j < (int)vvs[i].size(); ++j){
    			if (j == (int)vvs[i].size()-1) cout << vvs[i][j];
    			else cout << vvs[i][j] << ",";
    		}
    		cout << "}" << endl;
    	}
    	cout << endl;
    }
	else{
		if (not b[k]){
			for (int i = 0; i < (int)vvs.size(); ++i){
				b[k] = true;
				vvs[i].push_back(vs[k]);
				backtracking(k+1, vs);
				vvs[i].pop_back();
				b[k] = false;
			}
		}
	}
}

int main () {
	int n; cin >> n;

	VS vs(n);
	b = VB(n);

	for (int i = 0; i < n; ++i)
		cin >> vs[i];

	cin >> n;
	vvs = VVS(n, VS());

	backtracking(0, vs);
}
