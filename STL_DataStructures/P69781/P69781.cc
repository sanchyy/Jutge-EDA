#include <iostream>
#include <set>
using namespace std;

int main() {
    set <int> collatz;
    int count = 0;
    int x,y,n;
    while (cin >> x >> y >> n) {
        while (collatz.find(n) != collatz.end()) {
            collatz.insert(n);
            if (n%2 == 0)
                n = n/2 + x;
            else
                n = 3*n+y;
        }
        int aux;
        count = 1;
        if (n%2 == 0)
            n = n/2 + x;
        else
            n = 3*n+y;
        while (aux != n) {
            if (n%2 == 0)
                n = n/2 + x;
            else
                n = 3*n+y;
            ++count;
        }
        cout << count << endl;
    }
    
}
