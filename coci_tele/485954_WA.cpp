#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int n,m;
struct A {
	int ind,value;
};
vector<A> ve[3011];
int IN[3011];
int dp[3011][3011];
int order[3011];
int mxsize[3011];
int dis[3011];
int cost[3011];
int mincost[3011];
int main() {
	scanf("%d%d",&n,&m);
	int i,j,k,l;
	for(i=1;i<=n-m;i++) {
		int mm;
		scanf("%d",&mm);
		for(j=1;j<=mm;j++) {
			int a,b;
			scanf("%d%d",&a,&b);
			A aa;
			aa.ind = a;
			aa.value = b;
			ve[i].push_back(aa);
			IN[a]++;
		}
	}
	for(i=n-m+1;i<=n;i++) {
		scanf("%d",&cost[i]);
		IN[i]=-1;
		mxsize[i]=1;
	}
	int ind=-1;
	for(i=1;i<=n-m;i++) {
		for(j=1;j<=n-m;j++) {
			if(IN[j]==0) {
				ind=j;
				IN[j]=-1;
				break;
			}
		}
		for(j=0;j<ve[ind].size();j++) {
			IN[ve[ind][j].ind]--;
		}
		order[i]=ind;
	}

	for(i=1;i<=n-m;i++) for(j=1;j<=n;j++) dp[i][j]=-99999999;
	queue<int> qu;
	qu.push(1);
	while(!qu.empty()) {
		for(j=0;j<ve[qu.front()].size();j++) {
			qu.push(ve[qu.front()][j].ind);
			dis[ve[qu.front()][j].ind]=dis[qu.front()]+ve[qu.front()][j].value;
		}
		qu.pop();
	}
	for(i=n-m+1;i<=n;i++) dp[i][1]=cost[i];
	for(i=n-m+1;i<=n;i++) mxsize[i]=1;
	for(i=n-m;i>=1;i--) {
		ind = order[i];
		mincost[0]=0;
		for(k=1;k<=m;k++) mincost[k]=-999999999;
		for(j=0;j<ve[ind].size();j++) {
			for(k=0;k<=mxsize[ve[ind][j].ind];k++) {
				int adds=dp[ve[ind][j].ind][k]-ve[ind][j].value;
				for(l=mxsize[ind];l>=0;l--) {
					if(l==0 || mincost[l] > 0) {
						if(k+l <= m)
						if(mincost[l]+adds > mincost[l+k]) {
							mincost[l+k]=mincost[l]+adds; 
						if(mxsize[ind] < l+k) mxsize[ind]=l+k;
					}
				}
			}
		}
	}
		for(j=0;j<=mxsize[ind];j++) {
			dp[ind][j]=mincost[j];
		}
	}
	int ans=0;
	for(i=1;i<=m;i++) if(dp[1][i] >= 0) ans=i;
	printf("%d",ans);
}