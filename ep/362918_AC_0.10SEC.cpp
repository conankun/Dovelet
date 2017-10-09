#include<iostream>
#include<stdlib.h>
using namespace std;
int v,p;
int data[500];
int dp[500][500];
int dis[500][500];
int main() {
	int i,j,k,z;
	cin>>v>>p;
	for(i=1;i<=v;i++) {
		cin>>data[i];
	}
	data[v+1]=99999999;
	for(i=1;i<=v-1;i++) {
		for(j=i+1;j<=v+1;j++) {
			for(k=i+1;k<=j-1;k++) {
				if(abs(data[k]-data[j]) < abs(data[k]-data[i])) {
					dis[i][j]+=abs(data[k]-data[j]);
				} else {
					dis[i][j]+=abs(data[k]-data[i]);
				}
			}
		}
	}
	for(i=1;i<=v;i++) {
		for(j=1;j<=v;j++) {
			dp[1][i] += abs(data[i]-data[j]);
		}
	}
	for(i=1;i<=v;i++) {
		int sum=0;
		for(j=1;j<=v;j++) {
			sum+=abs(data[i]-data[j]);
		}
		dp[1][i]=sum;
	}
	for(i=2;i<=p;i++) {
		for(j=i;j<=v;j++) {
			dp[i][j]=99999999;
			for(k=i-1;k<=j-1;k++) {
				if(dp[i-1][k]-dis[k][v+1]+dis[k][j]+dis[j][v+1] < dp[i][j]) {
					dp[i][j] = dp[i-1][k]-dis[k][v+1]+dis[k][j]+dis[j][v+1];
				}
			}
		}
	}
	int min=9999999;
	for(i=p;i<=v;i++) {
		if(dp[p][i] < min) min = dp[p][i];
	}
	cout<<min;
}