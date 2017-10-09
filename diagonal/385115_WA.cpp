#include<iostream>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	if(m > n) {
		int temp = n;
		n = m;
		m = n;
	}
	if(n%m == 0) {
		cout<<n;
	} else {
		cout<<n+m-1;
	}
}