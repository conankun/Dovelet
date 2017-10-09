#include<iostream>
#include<vector>
using namespace std;
int n,s,e;
int mx=0;
struct A {
	int e,value;
};
vector<int> path;
vector<int> ans;
vector<A> map[1000];
int vis[1000];
int min(int a,int b) {
	if(a < b) return a;
	return b;
}
void DFS(int ind,int flow) {
	int i;
	if(ind == e) {
		if(mx < flow) {
			mx = flow;
			ans.clear();
			ans.resize(path.size());
			for(i=0;i<path.size();i++) {
				ans[i] = path[i];
			}
		}
	} else {
		for(i=0;i<map[ind].size();i++) {
			if(min(flow,map[ind][i].value) <= mx) continue;
			else if(vis[map[ind][i].e] == 0) {
				vis[map[ind][i].e]=1;
				path.push_back(map[ind][i].e);
				DFS(map[ind][i].e,min(flow,map[ind][i].value));
				vis[map[ind][i].e]=0;
				path.pop_back();
			}
		}
	}
}
void networkflow() {
	vis[s]=1;
	path.push_back(s);
	DFS(s,9999999);	
}
int main() {
	int a,b,c,i;
	cin>>n>>s>>e;
	while(cin>>a>>b>>c) {
		A d;
		d.e = b;
		d.value = c;
		map[a].push_back(d);
	}
	networkflow();
	cout<<mx<<endl;
	for(i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}