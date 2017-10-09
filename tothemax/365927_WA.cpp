#include<iostream>
using namespace std;
int n;
int map[1000][1000];
int dp[1000][1000];
int main() {
	cin>>n;
	int i,j,k,z;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			cin>>map[i][j];
		}
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			dp[i][j]=dp[i][j-1]+map[i][j];
		}
	}
	int mx=-2147483647;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			for(k=j;k<=n;k++) {
				int sum=0;
				for(z=i;z<=n;z++) {
					sum+=dp[z][k]-dp[z][j-1];
					if(sum > mx) {
						if(sum == 33) {
							printf("hi");
						}
						mx = sum;
					}
				}
			}
		}
	}
	cout<<mx;
}