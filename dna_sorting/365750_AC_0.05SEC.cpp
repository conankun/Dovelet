#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n,m;
struct A {
	string s;
	int value;
	int index;
	bool operator<(const A &a) const {
		if(value == a.value) return index < a.index;
		return value < a.value;
	}
};
A arr[1000];
int main() {
	cin>>n>>m;
	int i,j,k;
	for(i=0;i<m;i++) {
		cin>>arr[i].s;
	}
	for(i=0;i<m;i++) {
		int cnt=0;
		for(j=0;j<n;j++) {
			for(k=j+1;k<n;k++) {
				if(arr[i].s[j] > arr[i].s[k]) cnt++;
			}
		}
		arr[i].value = cnt;
		arr[i].index = i;
	}
	sort(arr,arr+m);
	for(i=0;i<m;i++) {
		cout<<arr[i].s<<endl;
	}
}