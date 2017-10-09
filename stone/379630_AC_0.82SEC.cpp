#include<iostream>
using namespace std;
int m,k;
int stone[1000];
int order[100];
int vis[100];
int ans=99999999;
void back(int ind,int cnt) {
	int dp[200][10]={0};
	if(cnt == k) {
		int i,j,z;
		for(i=1;i<=m;i++) {
			for(j=1;j<=k;j++) {
				int mn=99999999;
				for(z=1;z<=j;z++) {
					if(dp[i-1][z] < mn) mn = dp[i-1][z];
				}
				if(stone[i] != order[j]) dp[i][j]++;
				dp[i][j]+=mn;
			}
		}
		for(i=1;i<=k;i++) if(ans > dp[m][i]) ans = dp[m][i];
	} else {
		int i;
		for(i=1;i<=k;i++) {
			if(vis[i] == 0) {
				vis[i]=1;
				order[cnt+1]=i;
				back(i,cnt+1);
				vis[i]=0;
			}
		}
	}
}
int main() {
	cin>>m>>k;
	int d,i,j,z;
	for(i=1;i<=m;i++) cin>>stone[i];
	back(0,0);
	cout<<ans;
}