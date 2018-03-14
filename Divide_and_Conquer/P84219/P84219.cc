#include <iostream>
#include <vector>
using namespace std;


int Binary_search(double x, const vector<double>& v, int esq, int dre) {
	 
	if (esq > dre ) return -1;
	if (esq == dre) return (v[esq] == x) ? esq : -1;

	int mid = (esq+dre)/2;
	if (x < v[mid]) return Binary_search(x,v,esq,mid-1);
	if (x > v[mid]) return Binary_search(x,v,mid+1,dre);
	if (x == v[mid]) return Binary_search(x,v,esq,mid);
	
}

int first_occurrence(double x, const vector<double>& v) {
	int pos = Binary_search(x,v,0,v.size()-1);
	while(pos > 0 and v[pos-1] == x)
		--pos;
	return pos;
}


int main() {
	int size; cin >> size;
	vector <double> v(size);
	for(int i = 0; i < size; ++i)
		cin >> v[i];
	double x; cin >> x;
	cout << first_occurrence(x,v) << endl;
}