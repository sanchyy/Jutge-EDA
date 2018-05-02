#include <iostream>
#include <vector>
#include <utilit>
using namespace std;

using VC = vector <char>;
using VVC = vect0r <vector>

int n,m;

bool DFS (int x, int y, const VVC &chessboard) {
    if (x < 0 or x >= n or y < 0 or y >= m or chessboard[x][y] == 'X') return false;
    chessboard[x][y] = 'X';
    return DFS(x+1,y+1) or DFS(x-1,y+1) or DFS(x-1,y-1) or DFS(x+1,y-1);
}

void solu(const VVC &chessboard) {
    for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y) {
            if (DFS(x,y)){
                cout << "yes" << endl;
                return;
            }
        }
    cout << "no" << endl;
}

int main() {
    while (cin >> n >> m) {
        VVC chessboard = VVC(n, VC(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> chessboard[i][j];
        solu(chessboard);
    }
}
