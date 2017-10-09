#include<iostream>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;
int n,m;
struct A {
	int s,e,g;
};
int map[1000][1000];
A vert[10000];
int vis[1000];
int min(int a,int b) {
	if(a < b) return a;
	return b;
}
bool t=false;
vector<int> path;
int max_flow=0;
bool NF(int ind,int flow) {
	if(ind == n) {
		t=true;
		int i;
		for(i=0;i<path.size()-1;i++) {
			map[path[i]][path[i+1]]-=flow;
			map[path[i+1]][path[i]]+=flow;
		}
		max_flow+=flow;
		return true;
	} else {
		int i;
		bool tr=0;
		for(i=1;i<=n;i++) {
			if(map[ind][i] > 0 && vis[i] == 0 && !t) {
				vis[i]=1;
				path.push_back(i);
				NF(i,min(flow,map[ind][i]));
				path.pop_back();
			}
		}
	}
	return t;
}
void networkflow() {
	path.push_back(1);
	while(NF(1,99999999)) {
		t=false;
		path.clear();
		path.push_back(1);
		memset(vis,0,sizeof(int)*(n+1));
	}
}
int main() {
	cin>>n>>m;
	int i;
	for(i=1;i<=m;i++) {
		cin>>vert[i].s>>vert[i].e>>vert[i].g;
		map[vert[i].s][vert[i].e] += vert[i].g;
	}
	networkflow();
	memset(vis,0,sizeof(int)*(n+1));
	queue<int> qu;
	qu.push(1);
	while(!qu.empty()) {
		vis[qu.front()]=1;
		for(i=1;i<=n;i++) {
			if(vis[i] == 0 && map[qu.front()][i] > 0) {
				vis[i]=1;
				qu.push(i);	
			}
		}
		qu.pop();
	}
	int cnt=0;
	vector<int> ve;
	for(i=1;i<=m;i++) {
		if(vis[vert[i].s] == 1 && vis[vert[i].e] == 0) {
			cnt++;
			ve.push_back(i);
		}
	}
	cout<<max_flow<<" "<<cnt<<endl;
	for(i=0;i<ve.size();i++) cout<<ve[i]<<endl;
}