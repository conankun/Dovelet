#include<iostream>
using namespace std;
int n;
int main() {
	int size=1;
	cin>>n;
	for(;size<n;size*=2);
	int s=n;
	int cnt=0;
	cout<<size<<" ";
	while(s > 0) {
		if(s >= size) s-=size;
		size/=2;
		cnt++;
	}
	cout<<cnt-1;
}