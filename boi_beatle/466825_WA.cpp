#include<stdio.h>
long long n,m;
long long dis[301][301];
long long vis[301][301];
long long graph[301][301];
long long pos[301];
long long abs(long long x) {
	if(x<0) return -1*x;
	return x;
}
int main() {
	scanf("%lld%lld",&n,&m);
	int i,j,k;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) {
		dis[i][j]=-1;
		graph[i][j]=-1;
	}
	for(i=1;i<=n;i++) scanf("%lld",&pos[i]);
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(i==j) continue;
			graph[i][j] = abs(pos[i]-pos[j]);
		}
	}
	vis[0][0]=0;
	int p=0;
	for(i=1;i<=n;i++) dis[1][i] = abs(pos[i]);
	for(i=1;i<=n;i++) {
		long long mn=-1,s=-1,l=-1;
		for(k=1;k<=n;k++) {
			for(j=1;j<=n;j++) {
				if((mn == -1 || mn > dis[k][j]) && dis[k][j] != -1) {
					s = j;
					l = k;
					mn = dis[k][j];
				}
			}
		}
		for(j=1;j<=n;j++) {
			if(dis[l+1][j] == -1 || dis[l+1][j] > dis[l][s]+graph[s][j]) {
				if((l+1)*m >= dis[l][s]+graph[s][j] && vis[l+1][j]==0 && graph[s][j] != -1) dis[l+1][j] = dis[l][s]+graph[s][j];
			}
		}
		vis[l][s]=1;
	}
	long long ans = 0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(dis[i][j] != -1 && i*m-dis[i][j] > ans) {
				ans = i*m-dis[i][j];
			}
		}
	}
	printf("%lld",ans);
}