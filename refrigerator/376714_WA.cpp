#include<iostream>
#include<algorithm>
using namespace std;
struct A {
	int s,e;
	bool operator<(const A &a) const {
		return s < a.s;
	}
};
A arr[1000000];
int n;
int main() {
	cin>>n;
	int i;
	for(i=0;i<n;i++) cin>>arr[i].s>>arr[i].e;
	sort(arr,arr+n);
	int nowe=arr[0].e;
	int cnt=1;
	for(i=1;i<n;i++) {
		if(nowe < arr[i].s) {
			nowe = arr[i].e;
			cnt++;
		}
	}
	cout<<cnt;
}