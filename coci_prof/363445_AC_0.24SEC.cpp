#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct A {
	int value,index;
	bool operator<(const A &a) const {
		if(value == a.value) return index < a.index;
		return value < a.value;
	}
};
A arr[300000];
int dp[200000];
int s,p=999;
int ind=1;
int main() {
	int i;
	cin>>n;
	for(i=1;i<=n;i++) {
		int a,b;
		cin>>a>>b;
		arr[ind].index = i;
		arr[ind++].value = a;
		arr[ind].index = i;
		arr[ind++].value = b;
	}
	sort(arr+1,arr+ind);
	int ns=0,np=0;
	for(i=1;i<ind;i++) {
		if(arr[i-1].value == arr[i].value && arr[i-1].index == arr[i].index) continue;
		if(arr[i-1].value == arr[i].value && arr[i-1].index+1 == arr[i].index) {
			ns++;
		} else {
			ns=1;
			np = arr[i].value;
		}
		if(ns > s || (ns == s && p > np)) {
				s = ns;
				p = np;
		}
	}
	cout<<s<<" "<<p;
}