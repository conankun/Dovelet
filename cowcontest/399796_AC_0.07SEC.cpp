#include<iostream>
using namespace std;
int n,m;
int map[1000][1000];
int small[1000][1000];
int big[1000][1000];
int vis[1000];
int path[100000];
int ind;
void DFS(int edge) {
	int i;
	for(i=0;i<ind-1;i++) {
		small[edge][path[i]]=1;//[a][b] a가 b보다 작음.
		big[path[i]][edge]=1;//[a][b] a가 b보다 큼.
	}
	for(i=1;i<=n;i++) {
		if(vis[i] == 0 && map[edge][i] == 1) {
			path[ind++]=i;
			vis[i]=1;
			DFS(i);
			//vis[i]=0;
			path[ind--]=0;
		}
	}
}
int main() {
	cin>>n>>m;
	int i,j;
	for(i=1;i<=m;i++) {
		int a,b;
		cin>>a>>b;
		map[a][b]=1;
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) vis[j]=0;
		vis[i]=1;
		path[ind++]=i;
		DFS(i);
		path[ind--]=0;
		vis[i]=0;
	}
	int cnt=0;
	for(i=1;i<=n;i++) {
		int sum=0;
		for(j=1;j<=n;j++) {
			sum+=big[i][j];
			sum+=small[i][j];
		}
		if(sum == n-1) {
			cnt++;
		}
	}
	cout<<cnt;
}