#include<stdio.h>
#include<iostream>
using namespace std;
int n;
int point[9999],graph[6011][6011],parent[6011][6011],toposort[6011],IN[6011];
int root,qu[9999],vis[9999],D[3][6011];
int h=1,t,ind;
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&point[i]);
	int a,b;
	while(scanf("%d%d",&b,&a) != -1) {
		if(a==0&&b==0) break;
		graph[a][b]=1;
		parent[b][a]=1;
		IN[b]++;
	}
	for(i=1;i<=n;i++) {
		if(IN[i]==0) {
			root=i;
			break;
		}
	}
	qu[++t] = root;
	while(h<=t) {
		bool tr=0;
		for(i=1;i<=n;i++) {
			if(graph[qu[h]][i]==1&&vis[i]==0) {
				tr=1;
				vis[i]=1;
				qu[++t]=i;
			}
		}
		if(!tr) {
			toposort[++ind]=qu[h];
		}
		h++;
	}
	h=1,t=0;
	for(i=1;i<=ind;i++) {
		qu[++t]=toposort[i];
	}
	int ans=0;
	while(h<=t) {
		//D[0][qu[h]] = sum(D[1][k]);
		//D[1][qu[h]] = sum(D[0][k])+point[qu[h]];
		int s1=0,s2=0;
		for(i=1;i<=n;i++) {
			if(graph[qu[h]][i]==1) {
				s1+=D[0][i];
				s2+=max(D[0][i],D[1][i]);
			}
		}
		D[0][qu[h]] = s2;
		D[1][qu[h]] = s1+point[qu[h]];
		if(ans < D[0][qu[h]]) ans = D[0][qu[h]];
		if(ans < D[1][qu[h]]) ans = D[1][qu[h]];
		for(i=1;i<=n;i++) {
			if(parent[qu[h]][i]==1) {
				qu[++t]=i;
			}
		}
		h++;
	}
	printf("%d",ans);
}