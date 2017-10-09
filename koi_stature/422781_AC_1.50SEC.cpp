#include<stdio.h>
int map[1000][1000];
int sum[1000];
int vis[1000];
int small[1000][1000];
int big[1000][1000];
int path[1000];
int ind;
int n,m;
int count;
void dfs(int node) {
	int i;
	for(i=1;i<=ind;i++) {
		if(path[i]==node) continue;
		small[path[i]][node]=1;
		big[node][path[i]]=1;
	}
	for(i=1;i<=n;i++) {
		if(map[node][i]==1 && vis[i]==0) {
			vis[i]=1;
			path[++ind]=node;
			dfs(i);
			--ind;
		}
	}
}
int main() {
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		map[b][a]=1;
		sum[a]++;
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) vis[j]=0;
		ind=0;
		vis[i]=1;
		path[++ind]=i;
		dfs(i);
	}
	for(i=1;i<=n;i++) {
		int sum=0;
		for(j=1;j<=n;j++) sum+=big[i][j];
		for(j=1;j<=n;j++) sum+=small[i][j];
		if(sum == n-1) {
			count++;
		}
	}
	printf("%d",count);
}
