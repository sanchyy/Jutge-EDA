#include <iostream>
#include <vector>
using namespace std;


void merge(vector <int> &v, int left, int middle, int right, int &inversions) {

	int size = right-left;
	vector <int> merged(size+1);
	int i = left, j = middle+1, k = 0;
	while (i <= middle and j <= right){
		if (v[i] <= v[j])
			merged[k++] = v[i++];
		else{
			merged[k++] = v[j++];
			inversions = inversions + (middle + 1) - i;
		}
	}
	while (i <= middle)
		merged[k++] = v[i++];
	while (j <= right)
		merged[k++] = v[j++];
	for (i= 0; i <= size; ++i)
		v[left+i] = merged[i];
}


void merge_sort(vector <int> &v, int left, int right, int &inversions) {
	if (left < right) {
		int middle = (left+right)/2;
		merge_sort(v,left,middle,inversions);
		merge_sort(v,middle+1,right,inversions);
		merge(v,left,middle,right,inversions);
	}
}

int main() {
	int n;
	while (cin >> n) {
		vector <int> inv(n);
		for (int i = 0; i < n; ++i)
		cin >> inv[i];
		int inversions = 0;
		merge_sort(inv,0,n-1,inversions);
		cout << inversions << endl;
	}

}