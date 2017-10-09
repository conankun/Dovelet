#include<iostream>
#include<memory.h>
using namespace std;
int n,m,sum;
int chu[100];
int dp[20000];
int dp2[100000];
int main() {
	int i,j,k;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>chu[i];
		sum+=chu[i];
	}
	dp[0]=1;
	for(i=0;i<n;i++) {
		for(j=15000;j>=0;j--) {
			if(dp[j] != 0) {
				dp[j+chu[i]]=1;
			}
		}
	}
	cin>>m;
	for(i=0;i<m;i++) {
		int a;
		cin>>a;
		if(dp[a] != 0) {
			cout<<"Y ";
		} else {
			memset(dp2,0,sizeof(int)*100000);
			dp2[a]=1;
			bool t=false;
			for(j=0;j<n;j++) {
				for(k=sum;k>=0;k--) {
					if(dp2[k] != 0) {
						dp2[k+chu[j]]=1;
						if(dp[k+chu[j]]) {
							t=true;
							break;
						}
					}
				}
				if(t) break;
			}
			if(t) cout<<"Y ";
			else cout<<"N ";
		}
	}
}