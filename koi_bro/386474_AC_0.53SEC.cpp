#include<iostream>
#include<stdlib.h>
using namespace std;
int n;
int map[30][30];
int limit[30][30];
char back[30][30][40001];
short back2[30][30][40001];
bool dp[30][30][40001];
int ba[30];
int sum;
int main() {
	int i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			cin>>map[i][j];
			sum+=map[i][j];
		}
	}
	dp[n+1][0][0]=1;
	for(j=1;j<=n;j++) {
		dp[n+1][j][0]=1;
		int s=0;
		for(i=n;i>=1;i--) {
			s+=map[i][j];
			for(k=i;k<=n+1;k++) {
				for(l=0;l<=limit[k][j-1];l++) {
					if(dp[k][j-1][l] == 1) {
						dp[i][j][l+s]=1;
						back[i][j][l+s] = k;
						back2[i][j][l+s]=l;
						if(l+s > limit[i][j]) limit[i][j] = l+s;
					}
				}
			}
		}
	}
	int mn=999999999;
	int ind=0;
	int ind2=0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=limit[i][n];j++) {
			if(dp[i][n][j])
				if(abs((sum-j)-j) < mn) {
					mn = abs((sum-j)-j);
					ind = i;
					ind2 = j;
				}
		}
	}
	int temp,temp2;
	ba[n]=ind;
	temp = back[ind][n][ind2];
	temp2 = back2[ind][n][ind2];
	ind = temp;
	ind2 = temp2;
	for(i=n-1;i>=1;i--) {
		ba[i] = ind;
		temp = back[ind][i][ind2];
		temp2 = back2[ind][i][ind2];
		ind = temp;
		ind2 = temp2;
	}
	cout<<mn<<endl;
	for(i=1;i<=n;i++) {
		if(ba[i] == 0) cout<<0<<" ";
		else
		cout<<n+1-ba[i]<<" ";
	}
}