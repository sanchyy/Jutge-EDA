#include <iostream>
#include <vector>
using namespace std;


int Binary_search(double x, const vector<double>& v, int esq, int dre) {
	 
	if (esq > dre ) return -1;

	int mid = (esq+dre)/2;
	if (x < v[mid]) return Binary_search(x,v,esq,mid-1);
	if (x > v[mid]) return Binary_search(x,v,mid+1,dre);
	if (mid > 0 and x == v[mid-1]) return Binary_search(x,v,esq,mid-1);
	
}

int first_occurrence(double x, const vector<double>& v) {
	return Binary_search(x,v,0,v.size()-1);
}


int main() {
	int size; cin >> size;
	vector <double> v(size);
	for(int i = 0; i < size; ++i)
		cin >> v[i];
	double x; cin >> x;
	cout << first_occurrence(x,v) << endl;
}
