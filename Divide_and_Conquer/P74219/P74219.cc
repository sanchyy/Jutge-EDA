#include <iostream>
#include <vector>
using namespace std;

//Càlcul de Fibonacci

//M = {{1,1},{1,0}}

// M * (Fn-1 , Fn-2) = {{Fn-1+Fn-2},{Fn-1}} = {{Fn},{Fn-1}}


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
    int exp, mod;
    vector <vector <int> > fib_ini {{1},{0}};
    while (cin >> exp >> mod) {
        vector <vector <int> > mat {{1,1},{1,0}};
        mat = pow_mat(mat,exp,mod);
        mat = multipl(mat,fib_ini,mod);
        cout << mat[1][0] << endl;
        
    }
}
