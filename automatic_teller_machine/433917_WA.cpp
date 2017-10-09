#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct A {
	int I,F;
	bool operator<(const A &a) const {
		return F > a.F;
	}
};
int N,M,S,P,C[999999],R[999999],L,T,ST,V1[500011],V2[500011],V3[999999],D[999999],G[500011];
A F[500011];
vector<int> v[999999],d[999999];
queue<int> qu;
void dfs(int node) {
	V1[node]=1;
	int i;
	for(i=0;i<v[node].size();i++) {
		if(!V1[v[node][i]]) {
			dfs(v[node][i]);
		}
	}
	F[node].I=node;
	F[node].F=++L;
}
void dfs2(int node,int root) {
	V2[node]=1;
	C[root]+=C[node];
	C[node]=0;
	if(R[node]) R[root]=1;
	R[node]=0;
	G[node]=root;
	if(node == S) ST = root;
	int i;
	for(i=0;i<d[node].size();i++) {
		if(!V2[d[node][i]]) {
			dfs2(d[node][i],root);
		}
	}
}
int main() {
	scanf("%d%d",&N,&M);
	T=N;
	int i,j;
	for(i=1;i<=M;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
	}
	for(i=1;i<=N;i++) {
		scanf("%d",&C[i]);
	}
	scanf("%d%d",&S,&P);
	for(i=1;i<=P;i++) {
		int a;
		scanf("%d",&a);
		R[a]=1;
	}
	for(i=1;i<=N;i++) {
		if(V1[i]) continue;
		dfs(i);
	}
	stable_sort(F+1,F+1+N);
	for(i=1;i<=N;i++) {
		for(j=0;j<v[i].size();j++) {
			d[v[i][j]].push_back(i);
		}
	}
	for(i=1;i<=N;i++) {
		if(V2[F[i].I]) continue;
		++T;
		dfs2(F[i].I,T);
	}
	for(i=1;i<=N;i++) {
		for(j=0;j<v[i].size();j++) {
			v[G[i]].push_back(G[v[i][j]]);
		}
	}
	qu.push(ST);
	D[ST]=C[ST];
	V3[ST]=1;
	int ans=0;
	while(!qu.empty()) {
		if(ans < D[qu.front()]) ans = D[qu.front()];
		for(i=0;i<v[qu.front()].size();i++) {
			if(!V3[v[qu.front()][i]]) {
				V3[v[qu.front()][i]]=1;
				D[v[qu.front()][i]]=D[qu.front()]+C[v[qu.front()][i]];
				qu.push(v[qu.front()][i]);
			}
		}
		qu.pop();
	}
	printf("%d",ans);
}