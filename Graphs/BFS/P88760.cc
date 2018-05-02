#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct rock {
    double x,y,r;
    int jump;
};
using VE = vector <int>;
using VR = vector <rock>;
using Q = queue<int>;

VR rocks;
VE visit;
int n; double d;

bool can_jump(rock r1, rock r2, double d) {
    double sq1 = (r1.x-r2.x)*(r1.x-r2.x);
    double sq2 = (r1.y-r2.y)*(r1.y-r2.y);
    double sqr = sqrt(sq1 + sq2);
    double dist = sqr - r1.r - r2.r;
    return d >= dist;
}

int BFS(double d) {
    visit = VE(n,false);
    Q q;
    q.push(0);
    visit[0] = true;
    while (not q.empty()) {
        int r_i = q.front();
        rock r = rocks[r_i];
        q.pop();
        if (r_i == n-1)
            return r.jump;
        else {
            for (int i = 1; i < n; ++i) {
                if (i != r_i and not visit[i] and can_jump(r,rocks[i],d)) {
                    rocks[i].jump = r.jump +1;
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    while (cin >> n >> d) {
        rocks = VR(n);
        for (int i = 0; i < n; ++i) {
            cin >> rocks[i].x >> rocks[i].y >> rocks[i].r;
            rocks[i].jump = 0;
        }
        int jumps = BFS(d);
        if (jumps == -1)
            cout << "Xof!" << endl;
        else cout << jumps << endl;
    }
}
