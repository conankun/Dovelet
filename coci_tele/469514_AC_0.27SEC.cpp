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
int imsi[3011];
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
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) dp[i][j]=-999999999;
	for(i=n-m+1;i<=n;i++) dp[i][1]=cost[i];
	for(i=n-m+1;i<=n;i++) mxsize[i]=1;
	for(i=n-m;i>=1;i--) {
		ind = i;
		mincost[0]=0;
		for(k=1;k<=n;k++) mincost[k]=-999999999;
		for(j=0;j<ve[ind].size();j++) {
			for(l=0;l<=mxsize[ind]+mxsize[ve[ind][j].ind];l++) imsi[l]=-999999999;
			for(k=0;k<=mxsize[ve[ind][j].ind];k++) {
				int adds=dp[ve[ind][j].ind][k]-ve[ind][j].value;
				for(l=mxsize[ind];l>=0;l--) {
					if(mincost[l]+adds > imsi[l+k]) {
						imsi[l+k]=mincost[l]+adds; 
						if(mxsize[ind] < l+k) mxsize[ind]=l+k;
					}
				}
			}
			for(l=0;l<=mxsize[ind];l++) if(mincost[l]<imsi[l]) mincost[l]=imsi[l];
		}
		for(j=0;j<=mxsize[ind];j++) {
			dp[ind][j]=mincost[j];
		}
	}
	int ans=0;
	for(i=1;i<=m;i++) {
		if(dp[1][i] >= 0) {
			ans=i;
		}
	}
	printf("%d",ans);
	ans=ans;
}