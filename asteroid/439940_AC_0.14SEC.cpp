#include<stdio.h>
int n,k;
int map[1002][1002];
int vis[10000];
int path[10000];
int ind;
int cnt;
bool dfs(int node) {
	vis[node]=1;
	if(node == 1001) {
		int i;
		for(i=2;i<=ind;i++) {
			map[path[i-1]][path[i]]=0;
			map[path[i]][path[i-1]]=1;
		}
		cnt++;
		return true;
	} else {
		int i;
		for(i=0;i<=1001;i++) {
			if(map[node][i] && !vis[i]) {
				path[++ind]=i;
				bool s = dfs(i);
				--ind;
				if(s) return true;
			}
		}
		return false;
	}
}
void nf() {
	path[++ind]=0;
	int i;
	while(dfs(0)) {
		for(i=0;i<=1001;i++) vis[i]=0;
		vis[0]=1;
		path[++ind]=0;
	}
}
int main() {
	scanf("%d%d",&n,&k);
	int i,j;
	for(i=1;i<=k;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		map[a][500+b]=1;
		map[0][a]=1;
		map[500+b][1001]=1;
	}
	nf();
	printf("%d",cnt);
}