#include<stdio.h>
int n;
int book[1000000];
int tree[1000000];
int dp[1000000];
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%d",&book[i]);
		tree[book[i]]=i;
	}
	int ans=1;
	dp[1]=1;
	for(i=2;i<=n;i++) {
		dp[i]=tree[book[i]-1]<i?dp[tree[book[i]-1]]+1:1;
		if(ans < dp[i]) ans = dp[i];
	}
	printf("%d",n-ans);
}