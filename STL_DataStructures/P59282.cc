#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue <int> pq;
    string action;
    int number;
    int max;
    double sum = 0;
    bool first = true;
    while (cin >> action) {
        if (action == "number") {
            cin >> number;
            sum += number;
            if (first) {
                max = number;
                first = 0;
            }
            else if (max < number)
                max = number;

            pq.push(-number);
        }

        else {
            if (pq.empty())
                first = true;
            else {
                sum += pq.top();
                pq.pop();
            }
        }
        if (pq.empty())
            cout << "no elements" << endl;
        else 
            cout << "minimum: " << max << ", maximum: " << -pq.top() << ", average: " << sum/int(pq.size()) << endl;
    }
}
