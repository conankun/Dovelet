#include<stdio.h> 
#include<vector> 
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
int ST,n,m,s,p,res[500011],point[500011],groups,group[500011],inGroup[500011],In[500011],isChk[500011],toposort[500011],dis[500011];
//  n,m,s,p, 각각 인출금액,레스토랑여부,그룹수,그룹들   , 속해 있는 그룹,들어오는선분수,해당그룹에연결되었는지,끝나는시간.
int vis[500011],vis2[500011],c[500011];
vector<int> v[500011],d[500011],scc[500011];
struct A {
	int ind,roop;
};
stack<A> st;
int time;
void dfs(int root) {
	A a;
	a.ind = root;
	a.roop = -1;
	st.push(a);
	int i;
	while(!st.empty()) {
		A top = st.top();
		st.pop();
		vis[top.ind]=1;
		bool t=true;
		for(i=top.roop+1;i<v[top.ind].size();i++) {
			top.roop=i;
			if(!vis[v[top.ind][i]]) {
				vis[v[top.ind][i]]=1;
				st.push(top);
				a.ind = v[top.ind][i];
				a.roop = -1;
				st.push(a);
				t=false;
				break;
			}
		}
		if(top.roop == v[top.ind].size()-1 && t) {
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
		for(i=0;i<d[qu.front()].size();i++) {
			if(!vis2[d[qu.front()][i]]) {
				vis2[d[qu.front()][i]]=1;
				qu.push(d[qu.front()][i]);
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
		if(Q.front() != root) point[root]+=point[Q.front()];
		if(Q.front() == s) ST = root;
		if(res[Q.front()]) res[root]=1;
		for(i=0;i<v[Q.front()].size();i++) {
			if(isChk[inGroup[v[Q.front()][i]]] != root && inGroup[v[Q.front()][i]] != root) {
				scc[root].push_back(inGroup[v[Q.front()][i]]);
				In[inGroup[v[Q.front()][i]]]++;
			}
		}
		for(i=0;i<d[Q.front()].size();i++) {
			if(!vis2[d[Q.front()][i]]) {
				vis2[d[Q.front()][i]]=1;
				Q.push(d[Q.front()][i]);
			}
		}
		Q.pop();
	}
}
queue<int> topo;
int main() {
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
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
	for(i=1;i<=n;i++) {
		for(j=0;j<v[i].size();j++) {
			d[v[i][j]].push_back(i);
		}
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
		for(j=0;j<scc[ind].size();j++) {
			int imsi = scc[ind][j];
			In[scc[ind][j]]--;
			if(In[scc[ind][j]] == 0) {
				topo.push(scc[ind][j]);
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
		for(j=0;j<scc[toposort[i]].size();j++) {
			int imsi = scc[toposort[i]][j];
			if(dis[scc[toposort[i]][j]] > dis[toposort[i]]+point[scc[toposort[i]][j]]) {
				dis[scc[toposort[i]][j]]=dis[toposort[i]]+point[scc[toposort[i]][j]];
				c[scc[toposort[i]][j]]=1;
			}
		}
	}
	int ans=2147483647;
	for(i=1;i<=groups;i++) {
		if(dis[toposort[i]] < ans && res[toposort[i]] && c[toposort[i]]) ans = dis[toposort[i]];
	}
	printf("%d",ans*-1);
}