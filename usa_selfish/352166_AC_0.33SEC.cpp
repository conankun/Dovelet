#include<iostream>
#include<algorithm>
using namespace std;
int n;
int i,j;
struct A {
    int s,e;
};
A arr[1000000];
bool cmp(A a,A b) {
	if(a.e == b.e) return a.s < b.s;
    return a.e < b.e;
}
int main() {
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>arr[i].s>>arr[i].e;
    }
	sort(arr,arr+n,cmp);
	int lasttime=0;
	int cnt=0;
	for(i=0;i<n;i++) {
		if(arr[i].s >= lasttime) {
			cnt++;
			if(arr[i].e > lasttime) lasttime = arr[i].e;
		}
	}
	cout<<cnt;
}