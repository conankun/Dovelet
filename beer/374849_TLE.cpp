#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++) {
		for(j=1;j<=i;j++) {
			for(k=1;k<=j;k++) {
				if(i*j*k == n) {
					cout<<i<<" "<<j<<" "<<k<<endl;
					return 0;
				}
			}
		}
	}
}