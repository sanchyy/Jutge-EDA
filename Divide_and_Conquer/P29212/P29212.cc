#include <iostream>
using namespace std;

//k parell: n^k = (n^(k/2)))²
// k imparell: n^k = (n^(k/2))²*n

int i_pow(int base, int exponent, int modul) {
	/*int result = 1;
	while (exponent > 0) {
		if (exponent % 2 == 1) 
			result = (result * base) % modul;
		exponent = exponent >> 1;
		base = (base * base) % modul;
	}
	return result;*/
	
	if (exponent == 0)
		return 1;
	int result = i_pow(base,exponent/2,modul);
	result = (result * result) % modul;
	if (exponent % 2)
		result = (result * base) % modul;
	return result;
}

int main() {
	int n, k, m;
	while (cin >> n >> k >> m) {
		cout << i_pow(n, k, m) << endl;
	}
}
