#include<iostream>
using namespace std;
int n;
int C[1000][1000];
int main() {
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) {
		C[i][0]=1;
		C[i][i]=1;
		for(j=1;j<i;j++) {
			C[i][j] = C[i-1][j]+C[i-1][j-1];
		}
	}
	int sum=0;
	for(i=1;i<=n-1;i++) {
		j = n-i-1;
		if(i >= j) {
			sum+=C[n-j][i]*C[n-i-1][j];
		}
	}
	if(n == 1 || n == 2) cout<<1;
	else cout<<sum;
}