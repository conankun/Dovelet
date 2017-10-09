#include<stdio.h>
#define max(a,b) a>b?a:b
int dp[1000000];
int N;
struct A {
	int t,h;
}book[1000000];
int ans=-1;
void parametric(int low,int high) {
	if(low>high) return;
	int mid=(low+high)/2;
	int i,j;
	for(i=1;i<=N;i++) {
		int mx=0,ss=0;
		dp[i]=2147483647;
		for(j=i;j>=1;j--) {
			ss+=book[j].t;
			if(book[j].h  > mx) mx = book[j].h;
			if(dp[i] > dp[j-1]+mx) {
				dp[i]=dp[j-1]+mx;
			}
			if(ss+book[j-1].t > mid) break;
		}
	}
	if(ans == -1 || max(dp[N],mid) < ans) ans = max(dp[N],mid);
	if(dp[N] > mid) {
		parametric(mid+1,high);
	} else if(dp[N] < mid) {
		parametric(low,mid-1);
	}
}
int main() {
	scanf("%d",&N);
	int i;
	int mx=0;
	for(i=1;i<=N;i++) {
		scanf("%d%d",&book[i].t,&book[i].h);
		if(book[i].t > mx) mx = book[i].t;
	}
	parametric(1,1000000);
	printf("%d",ans);
	
}