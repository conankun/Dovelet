#include<iostream>
#include<memory.h>
using namespace std;
int ctr[110];
int vis[110];
int n;
int v[110][110];
void DFS(int ind,int r) {
	int i;
	vis[ind]=1;
	for(i=1;i<=n;i++) {
		if(v[ind][i] > 0) {
			if(v[r][ind] >= 50 || ctr[ind] >= 50) ctr[i]+=v[ind][i];
			if(vis[i] == 0 && (v[ind][i] >= 50 || ctr[i] >= 50)) DFS(i,ind);
		}
	}
}
int main() {
	int a,b,c;
	int m;
	cin>>m;
	while(cin>>a>>b>>c) {
		if(a > n) n = a;
		if(b > n) n = b;
		v[a][b] += c;
		m--;
		if(m<=0) break;
	}
	int i,j;
	for(i=1;i<=n;i++) {
		v[i][i] = 50;
		memset(vis,0,sizeof(int)*110);
		memset(ctr,0,sizeof(int)*110);
		DFS(i,i);
		for(j=1;j<=n;j++) {
			if(i == j) continue;
			if(ctr[j] >= 50 || v[i][j] >= 50) cout<<i<<" "<<j<<endl;
		}
	}
}
