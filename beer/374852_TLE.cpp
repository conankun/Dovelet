#include<iostream>
using namespace std;
int main() {
	long long int n;
	cin>>n;
	long long int i,j,k;
	for(i=1;i<=n;i++) {
		for(j=1;j<=i;j++) {
			if(i*j > n) break;
			if(n%(i*j) == 0 && n/(i*j) <= j) {
				cout<<i<<" "<<j<<" "<<n/(i*j);
				return 0;
			}
		}
	}
}