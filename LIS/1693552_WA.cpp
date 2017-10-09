#include<algorithm>
#include<iostream>
using namespace std;
struct A{
	int given, place;
};
int inds = 0;
int size = 1;
int guhggu[5000909];
int dyn[500999];
int temp[500911];
int tree[500090];
A indexedtrees[500090];
A arry[500011] = { 0 };
int stored[500011];
A oneroot[5000900];
A arry2[500011];
bool booly(A a, A b){
	return a.given < b.given;
}
int max(int a, int b){
	if (b - a > 0){
		return b;
	}
	return a;
}

int main(void){
	int n, i, j;
	cin >> n;
	for (i = 1; i <= n; i++){
		cin >> arry[i].given;
		arry[i].place = i;
		arry2[i] = arry[i];
	}
	for (size = 1; size < n; size *= 2);
	sort(arry + 1, arry + n + 1, booly);
	for (i = 0; i < n; i++){
		temp[i + 1] = (arry[i].given == arry[i + 1].given ? 0 : 1) + temp[i];
	}
	for (i = 1; i <= n; i++){
		tree[arry[i].place] = temp[i];
	}
	int length = 0;
	int f = 0;
	for (i = 1; i <= n; i++){
		int l = size, r = size + tree[i] - 2;
		bool t = true;
		int mx = 0;
		int ind = 0;
		while (l <= r && t){
			if (l == r){
				t = false;
			}
			if (l % 2 == 1){
				if (indexedtrees[l].given > mx){
					mx = indexedtrees[l].given;
					ind = indexedtrees[l].place;
				}
				l++;
			}
			if (r % 2 == 0) {
				if (indexedtrees[r].given > mx) {
					mx = indexedtrees[r].given;
					ind = indexedtrees[r].place;
				}
				r--;
			}
			l /= 2;
			r /= 2;
		}
		mx++;
		if (mx > length){
			length = mx;
			f = i;
		}
		guhggu[i] = ind;
		int rw = size + tree[i] - 1;
		while (rw > 0){
			if (indexedtrees[rw].given < mx){
				indexedtrees[rw].given = mx;
				indexedtrees[rw].place = i;
			}
			rw /= 2;
		}
	}
	printf("%d\n", length);
	int tt = f;
	dyn[inds++] = f;
	while (tt != 0) {
		tt = guhggu[tt];
		if (tt == 0) break;
		dyn[inds++] = tt;
	}
	for (int i = inds - 1; i >= 0; i--) {
		printf("%d ", arry2[dyn[i]].given);
	}
}