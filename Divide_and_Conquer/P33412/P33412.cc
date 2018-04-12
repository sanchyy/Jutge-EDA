#include <iostream>
#include <vector>
using namespace std;



bool imm_resistant_search(double x, const vector <double> &v, int i, int j) {
	int mid = (i + j)/2;
	if (i > j)
		return false;
	if (v[mid] == x)
		return true;
	else if (mid > 0 and v[mid-1] == x)
		return true;
	else if (mid < v.size() -1 and v[mid+1] == x)
		return true;
	else if (v[mid] > x)
		return imm_resistant_search(x,v,i,mid-1);
	else if (v[mid] < x)
		return imm_resistant_search(x,v,mid+1,j);
}

bool resistant_search(double x, const vector<double>& v) {
	int size = v.size();
	return imm_resistant_search(x,v,0,size-1);
}


int main() {
	return 0;
} 
