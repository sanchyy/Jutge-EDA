#include <iostream>
#include <vector>
using namespace std;

vector < vector<int> > multipl (const vector < vector <int> > &m1, const vector < vector <int> > &m2,int mod) {
    vector <vector <int> > prod (2,vector <int> (2));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                prod[i][j] =  (prod[i][j] + m1[i][k] * m2[k][j])%mod;
    return prod;
}

vector < vector <int> > pow_mat (const vector <vector <int> > & mat, int exp, int mod) {
    if (exp == 0) return vector <vector <int> > {{1,0},{0,1}};
    vector <vector <int> > result = pow_mat(mat,exp/2,mod);
    result = multipl(result,result,mod);
    if (exp % 2) 
        result = multipl(result,mat,mod);
    return result;
}

int main() {
	vector <vector <int> > mat (2,vector <int> (2));
	int exp,mod;
	while  (cin >>mat[0][0] >> mat[0][1] >> mat[1][0] >> mat[1][1] >> exp >> mod) {
		mat = pow_mat(mat,exp,mod);
        for (int i = 0; i < 2; ++i) 
            for (int j = 0; j < 2; ++j) {
                if (j == 0) cout << mat[i][j];
                else cout <<" " <<  mat[i][j] << endl;
            }
            
		cout << "----------" << endl;
	}
}
