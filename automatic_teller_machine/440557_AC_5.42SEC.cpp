#include<stdio.h>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct TLE {
	int value,ind;
	bool operator<(const TLE &a) const {
		return value < a.value;
	}
}Time[500011];
struct Edge {
	int s,e;
	bool operator<(const Edge& a) const {
		if(s == a.s) return e < a.e;
		return s < a.s;
	}
}v[500011],d[500011],scc[500011];
int sccind;
struct EdgeType {
	int start,end;	
}vsize[500011],dsize[500011],sccsize[500011];
int ST,n,m,s,p,res[500011],point[500011],groups,group[500011],inGroup[500011],In[500011],isChk[500011],toposort[500011],dis[500011];
//  n,m,s,p, 각각 인출금액,레스토랑여부,그룹수,그룹들   , 속해 있는 그룹,들어오는선분수,해당그룹에연결되었는지,끝나는시간.
int vis[500011],vis2[500011],c[500011];
struct A {
	int ind,roop;
};
stack<A> st;
int time;
void dfs(int root) {
	A a;
	a.ind = root;
	a.roop = vsize[root].start-1;
	st.push(a);
	int i;
	while(!st.empty()) {
		A top = st.top();
		st.pop();
		vis[top.ind]=1;
		bool t=true;
		for(i=top.roop+1;i<=vsize[top.ind].end;i++) {
			top.roop=i;
			if(i==0) break;
			if(!vis[v[i].e]) {
				vis[v[i].e]=1;
				st.push(top);
				a.ind = v[i].e;
				a.roop = vsize[v[i].e].start-1;
				st.push(a);
				t=false;
				break;
			}
		}
		if(top.roop == vsize[top.ind].end && t) {
			Time[top.ind].value=++time;
			Time[top.ind].ind = top.ind;
		}
	}
}
queue<int> qu;
void bfs(int root) {
	qu.push(root);
	int i;
	while(!qu.empty()) {
		vis2[qu.front()]=1;
		inGroup[qu.front()]=root;
		for(i=dsize[qu.front()].start;i<=dsize[qu.front()].end;i++) {
			if(!vis2[d[i].e]) {
				vis2[d[i].e]=1;
				qu.push(d[i].e);
			}
		}
		qu.pop();
	}
}
queue<int> Q;
void bfs2(int root) {
	Q.push(root);
	int i;
	while(!Q.empty()) {
		vis2[Q.front()]=1;
		isChk[inGroup[Q.front()]]=root;
		if(Q.front() != root) point[root]+=point[Q.front()];
		if(Q.front() == s) ST = root;
		if(res[Q.front()]) res[root]=1;
		for(i=vsize[Q.front()].start;i<=vsize[Q.front()].end;i++) {
			if(i==0) break;
			if(isChk[inGroup[v[i].e]] != root && inGroup[v[i].e] != root) {
				scc[++sccind].s=root;
				scc[sccind].e=inGroup[v[i].e];
				In[inGroup[v[i].e]]++;
			}
		}
		for(i=dsize[Q.front()].start;i<=dsize[Q.front()].end;i++) {
			if(!vis2[d[i].e]) {
				vis2[d[i].e]=1;
				Q.push(d[i].e);
			}
		}
		Q.pop();
	}
}
queue<int> topo;
int main() {	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		v[i].s = a;
		v[i].e = b;
	}
	stable_sort(v+1,v+1+m);
	for(i=1;i<=m;i++) {
		if(vsize[v[i].s].start == 0) vsize[v[i].s].start = i;
		if(v[i].s != v[i+1].s) vsize[v[i].s].end = i;
	}
	for(i=1;i<=n;i++) {
		scanf("%d",&point[i]);
	}
	scanf("%d%d",&s,&p);
	for(i=1;i<=p;i++) {
		int a;
		scanf("%d",&a);
		res[a]=1;
	}
	for(i=1;i<=n;i++) {
		if(vis[i]) continue;
		dfs(i);
	}
	stable_sort(Time+1,Time+1+n);
	for(i=1;i<=m;i++) {
		d[i].s = v[i].e;
		d[i].e = v[i].s;
	}
	stable_sort(d+1,d+1+m);
	for(i=1;i<=m;i++) {
		if(dsize[d[i].s].start == 0) dsize[d[i].s].start = i;
		if(d[i].s != d[i+1].s) dsize[d[i].s].end = i;
	}
	for(i=n;i>=1;i--) {
		if(vis2[Time[i].ind]) continue;
		groups++;
		group[groups]=Time[i].ind;
		bfs(Time[i].ind);
	}
	for(i=1;i<=n;i++) vis2[i]=0;
	for(i=n;i>=1;i--) {
		if(vis2[Time[i].ind]) continue;
		bfs2(Time[i].ind);
	}
	stable_sort(scc+1,scc+1+sccind);
	for(i=1;i<=sccind;i++) {
		if(sccsize[scc[i].s].start == 0) sccsize[scc[i].s].start = i;
		if(scc[i].s != scc[i+1].s) sccsize[scc[i].s].end = i;
	}
    int ind=-1;
    for(i=1;i<=n;i++) {
		point[i]*=-1;
		dis[i]=point[i];
	}
	for(i=1;i<=groups;i++) {
		if(In[group[i]]==0) {
			ind = group[i];
			dis[ind]=point[ind];
			topo.push(ind);
		}
	}
	for(i=1;i<=groups;i++) {
		ind = topo.front();
		topo.pop();
		int ind2=-1;
		In[ind]=-1;
		toposort[i] = ind;
		for(j=sccsize[ind].start;j<=sccsize[ind].end;j++) {
			int imsi = scc[j].e;
			In[scc[j].e]--;
			if(In[scc[j].e] == 0) {
				topo.push(scc[j].e);
			}
		}
	}
	int stgroup=-1;
	for(i=1;i<=groups;i++) {
		if(toposort[i] == ST) {
			stgroup = i;
			break;
		}
	}
	for(i=stgroup;i<=groups;i++) {
		for(j=sccsize[toposort[i]].start;j<=sccsize[toposort[i]].end;j++) {
			int imsi = scc[j].e;
			if(dis[scc[j].e] > dis[toposort[i]]+point[scc[j].e]) {
				dis[scc[j].e]=dis[toposort[i]]+point[scc[j].e];
				c[scc[j].e]=1;
			}
		}
	}
	int ans=2147483647;
	for(i=1;i<=groups;i++) {
		if(dis[toposort[i]] < ans && res[toposort[i]] && c[toposort[i]]) ans = dis[toposort[i]];
	}
	printf("%d",ans*-1);
}