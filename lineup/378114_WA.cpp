#include<iostream>
#include<queue>
using namespace std;
int n,k;
int cows[100001];
int isLast[100001];
int vis[100001];
int chk[100001];
int main() {
	scanf("%d%d",&n,&k);
	int i,j;
	int mn=99999999;
	for(i=1;i<=n;i++) {
		scanf("%d",&cows[i]);
	}
	for(i=n;i>=1;i--) {
		if(vis[cows[i]]==0) {
			isLast[i]=true;
		}
		vis[cows[i]]++;
	}
	int t=1;
	for(i=1;i<=n;i++) {
		if(isLast[i]) {
			int mi=999999999;
			for(j=1;j<=k;j++) if(chk[j] < mi) mi = chk[j];
			if(mn > mi+2) mn = mi+2;
		}
		++chk[cows[i]];
	}
	for(i=1;i<=k;i++) if(chk[i] == 0) mn=1;
	cout<<mn;
}