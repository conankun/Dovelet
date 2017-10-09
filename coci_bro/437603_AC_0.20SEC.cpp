#include<stdio.h>
int n;
int p[5001],vis[5001];
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	int cnt=0;
	for(i=2;i<=n;i++) {
		if(vis[i]) continue;
		int t = p[i]-p[1];
		int last = p[i];
		cnt++;
		for(j=i+1;j<=n;j++) {
			if(p[j] == last+t) {
				last = p[j];
				vis[j]=1;
			}
		}
	}
	printf("%d",cnt);
}