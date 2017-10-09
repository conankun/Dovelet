#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
struct Find {
	int s,e,data,root;
	bool operator<(const Find &f) const {
		return data < f.data;
	}
}finds[100000];
struct Edge {
	int s,e,v;
	char direction;
}edge[100000];
struct POS {
	int x,y;
}pos[100000];
int group[100000];
int N,M,K;
int pushs[100000];
int union_find(int x) {
	int ind=0,i;
	while(group[x] != x) {
		if(group[x] != group[group[x]]) pushs[++ind]=x;
		x=group[x];
	}
	for(i=1;i<=ind;i++) group[pushs[i]]=x;
	return x;
}
int Q[100000];
int h=1,t=1;
struct A {
	int e,v;
	char d;
};
vector<A> ve[100000];
int vis[100000];
char ex[100];
int prints[100000];
int main() {
	scanf("%d%d",&N,&M);
	int i,j;
	ex['N']='S';
	ex['S']='N';
	ex['E']='W';
	ex['W']='E';
	for(i=1;i<=M;i++) {
		scanf("%d%d%d\n%c\n",&edge[i].s,&edge[i].e,&edge[i].v,&edge[i].direction);	
		A a;
		a.e = edge[i].e;
		a.d = edge[i].direction;
		a.v = edge[i].v;
		ve[edge[i].s].push_back(a);
		a.e = edge[i].s;
		a.d=ex[edge[i].direction];
		ve[edge[i].e].push_back(a);
	}
	vis[1]=1;
	Q[t]=1;
	while(h<=t) {
		for(i=0;i<ve[Q[h]].size();i++) {
			if(vis[ve[Q[h]][i].e]==0) {
				if(ve[Q[h]][i].d=='N') {
					pos[ve[Q[h]][i].e].x=pos[Q[h]].x;
					pos[ve[Q[h]][i].e].y=pos[Q[h]].y-ve[Q[h]][i].v;
				}
				if(ve[Q[h]][i].d=='S') {
					pos[ve[Q[h]][i].e].x=pos[Q[h]].x;
					pos[ve[Q[h]][i].e].y=pos[Q[h]].y+ve[Q[h]][i].v;
				}
				if(ve[Q[h]][i].d=='E') {
					pos[ve[Q[h]][i].e].x=pos[Q[h]].x+ve[Q[h]][i].v;
					pos[ve[Q[h]][i].e].y=pos[Q[h]].y;	
				}
				if(ve[Q[h]][i].d=='W') {
					pos[ve[Q[h]][i].e].x=pos[Q[h]].x-ve[Q[h]][i].v;
					pos[ve[Q[h]][i].e].y=pos[Q[h]].y;
				}
				vis[ve[Q[h]][i].e]=1;
				int imsi = ve[Q[h]][i].e;
				Q[++t]=imsi;
			}
		}
		h++;
	}
	for(i=1;i<=N;i++) group[i]=i;
	scanf("%d",&K);
	for(i=1;i<=K;i++) {
		scanf("%d%d%d",&finds[i].s,&finds[i].e,&finds[i].data);
		finds[i].root=i;
	}
	sort(finds+1,finds+1+K);
	for(i=1;i<=K;i++) {
		if(finds[i].data != finds[i-1].data) {
			for(j=finds[i-1].data+1;j<=finds[i].data;j++) {
				int one = union_find(edge[j].s);
				int two = union_find(edge[j].e);
				group[edge[j].s]=min(one,two);
				group[edge[j].e]=min(one,two);
			}
		}
		int one=union_find(finds[i].s);
		int two=union_find(finds[i].e);
		group[finds[i].s]=min(one,two);
		group[finds[i].e]=min(one,two);
		if(group[finds[i].s] != group[finds[i].e]) {
			prints[finds[i].root]=-1;
		} else {
			prints[finds[i].root]=abs(pos[finds[i].s].x-pos[finds[i].e].x)+abs(pos[finds[i].s].y-pos[finds[i].e].y);	
		}
	}
	for(i=1;i<=K;i++) printf("%d\n",prints[i]);
}