#include<iostream>
#include<algorithm>
using namespace std;
int n;
int ropes[10000];
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) cin>>ropes[i];
	sort(ropes+1,ropes+1+n);
	int mx=0;
	for(i=0;i<n;i++) {
		if(ropes[n-i]*(i+1) > mx) mx = ropes[n-i]*(i+1);
	}
	cout<<mx;
}