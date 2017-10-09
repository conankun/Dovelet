#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct A {
	int s,e,v;
	bool operator<(const A &a) const {
		if(a.s == s) return e < a.e;
		return s < a.s;
	}
}vertex[10000];
int m,isVis[10000],In[10000],start[10000],end[10000],dis[10000];
int ind;
queue<int> qu;
queue<int> toposort;
int main() {
	int a,b;
	while(scanf("%d%d",&a,&b) != -1) {
		A aa;
		aa.s = a,aa.e = b,aa.v = -1,isVis[a]=1,isVis[b]=1;
		vertex[++m]=aa;
		In[b]++;
	}
	int i,j;
	toposort.push(0);
	for(i=1;i<=10000;i++) {
		if(isVis[i]==1&&In[i]==0) {
			A aa;
			aa.s = 0,aa.e = i,aa.v = 0,vertex[++m]=aa;
			qu.push(i);
			toposort.push(i);
		}
	}
	sort(vertex+1,vertex+1+m);
	for(i=1;i<=m+1;i++) {
		if(vertex[i].s != vertex[i-1].s) {
			if(i!=m+1) start[vertex[i].s]=i;
			end[vertex[i-1].s]=i-1;
		}
	}
	while(!qu.empty()) {
		int top = qu.front();
		qu.pop();
		for(j=start[top];j<=end[top];j++) {
			In[vertex[j].e]--;
			if(In[vertex[j].e]==0) {
				qu.push(vertex[j].e);
				toposort.push(vertex[j].e);
			}
		}
	}
	int ans=2147483647;
	while(!toposort.empty()) {
		int top = toposort.front();
		toposort.pop();
		for(i=start[top];i<=end[top];i++) {
			if(dis[top]+vertex[i].v < dis[vertex[i].e]) {
				dis[vertex[i].e]=dis[top]+vertex[i].v;
				if(dis[vertex[i].e] < ans) ans = dis[vertex[i].e];
			}
		}
	}
	printf("%d",-1*ans);
}
