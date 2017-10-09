#include<iostream>
using namespace std;
int gcd(int a,int b) {
	int c;
	do {
		c = a%b;
		a = b;
		b = c;
	}while(c != 0);
	return a;
}
int main() {
	int n,m;
	cin>>n>>m;
	cout<<n+m-gcd(n,m);	
}