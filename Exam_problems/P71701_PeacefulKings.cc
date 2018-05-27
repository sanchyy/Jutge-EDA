#include <iostream>
#include <vector>
#include <utility>
using namespace std;

using VC  = vector <char>;
using VVC = vector <char>;
using VE  = vector <int>;
using VVE = vector <VE>;

int n,k;
VVE B;

bool possible (int x, int y) {
    for (int i = x-1; i <= x+1; ++i)
        for (int j = y-1; j <= y+1; ++j) {
            if ((i >= 0 && i < n) && (j >= 0 && j < n) && B[i][j])
                return false;
        }
    return true;
}

void move (int i, int j, int &new_i, int &new_j) {
    if (j < n-1) {
        new_i = i;
        new_j = j+1;
    }
    else {
        new_i = i+1;
        new_j = 0;
    }
}

void f(int i, int j, int s, int k) {
    if (k == s) {
        for (int x = 0; x < n; ++x){
            for (int y = 0; y < n; ++y) {
                cout << (B[x][y] ? "K" : ".");
            }
            cout << endl;
        }
        cout << "----------" << endl;
    }
    else if (i != n){

        int new_i, new_j;
        move(i,j,new_i,new_j);

        if (possible(i,j)) {
            B[i][j] = true;
            f(new_i, new_j,s+1, k);
        }
        B[i][j] = false;
        f(new_i,new_j,s,k);
    }

}

int main() {
    cin >> n >> k;
    B = VVE(n,VE(n,false));
    f(0,0,0,k);


}
