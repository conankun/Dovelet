#include<iostream>
using namespace std;
char c[1000000];
int n;
void divcon(int s,int e) {
	int i;
	int a = e-s+1;
	for(i=s+a/3;i<=s+a/3+a/3-1;i++) {
		c[i]=' ';
	}
	if(e-s <= 2) return;
	divcon(s,s+a/3-1);
	divcon(s+a/3+a/3,e);
}
int main() {
	cin>>n;
	if(n == 0) {
		cout<<"-";
	} else {
		int t=1;
		int i;
		for(i=1;i<=n;i++) t*=3;
		for(i=1;i<=t;i++) c[i]='-';
		divcon(1,t);
		for(i=1;i<=t;i++) cout<<c[i];
	}
}