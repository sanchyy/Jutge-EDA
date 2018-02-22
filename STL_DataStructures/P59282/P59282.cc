#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue <int> pq;
    string action;
    int number;
    int max = ;
    int sum;
    while (cin >> action) {
        if (action == "delete") {
            if (pq.empty())
                cout << "no elements" << endl;
            else {
                summ += pq.top();
                pq.pop();
            }
        }
        
        else {
            cin >> number;
            summ += number;
            if (number > max)
                max = number;
            pq.push(-number);
            cout << "minimum: " << -pq.top() << ", maximum: " << max << ", average: " << sum/int(pq.size()) << endl;
        }
        
    }
}
