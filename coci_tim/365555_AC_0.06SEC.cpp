#include<iostream>
#include<cmath>
using namespace std;
int n,m,k;
int min(int a,int b) {
	if(a < b) return a;
	return b;
}
int main() {
	cin>>n>>m>>k;
	int t = min(n/2,m);
	int div=n-(t*2);
	div+=m-t;
	k-=div;
	if(k > 0)
	t-=ceil(k/3.00);
	cout<<t;
}