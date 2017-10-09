#include<iostream>
using namespace std;
int main() {
	long long n;
	cin>>n;
	long long i,j,k;
	for(i=1;i<=n;i++) {
		if(n%i == 0) for(j=1;j<=i;j++) {
			if(i*j > n) break;
			if(n%(i*j) == 0 && n/(i*j) <= j) {
				cout<<i<<" "<<j<<" "<<n/(i*j);
				return 0;
			}
		}
	}
}