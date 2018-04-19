#include <iostream>
#include <queue>
using namespace std;

int main() {
	char c;
	priority_queue <int> numbers;
	int num;
	while (cin >> c) {

		if ((c == 'A' or c == 'R' or c == 'D' or c == 'I') and numbers.empty()) 
			cout << "error!" << endl;

		else {
			if (c == 'S') {
				cin >> num;
				numbers.push(num);
			}
			else if (c == 'A')
				cout << numbers.top() << endl;
			else if (c == 'R') 
				numbers.pop();

			else if (c == 'I') {
				cin >> num;
				int aux = numbers.top();
				numbers.pop();
				aux += num;
				numbers.push(aux);
			}

			else if (c == 'D') {
				cin >> num;
				int aux = numbers.top();
				numbers.pop();
				aux -= num;
				numbers.push(aux);
			}
		}
	}
}
