#include<iostream>
using namespace std;
int num[10000];
int price[10000];
int numbers[10000];
int dp[10000];
int pos[10000];
int m,n;
int main() {
	scanf("%d %d",&m,&n);
	int i,j;
	for(i=1;i<=m;i++) {
		scanf("%d",&numbers[i]);
		pos[numbers[i]]=i;
	}
	for(i=1;i<=n;i++) {
		scanf("%d",&num[i]);
	}
	for(i=1;i<=n;i++) {
		scanf("%d",&price[i]);
	}
	int ans=999999999;
	for(i=1;i<=n;i++) {
		int mn=999999999;
		for(j=1;j<i;j++) {
			if(mn > dp[j] && pos[num[j]] == pos[num[i]]-1) {
				mn = dp[j];
			}
		}
		dp[i] = mn+price[i];
		if(pos[num[i]]==1) dp[i] = price[i];
		if(pos[num[i]] == m) {
			if(ans > dp[i]) ans = dp[i];
		}
	}
	if(ans == 999999999) printf("impossible");
	else printf("%d",ans);
}