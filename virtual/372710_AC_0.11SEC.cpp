#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
int n,s,end;
int mx=0;
struct A {
	int e,value;
};
ifstream in("input.txt");
vector<int> path;
vector<int> ans;
vector<A> map[1000];
int vis[1000];
int flow[1000];
int inqueue[1000];
int back[1000];
int max(int a,int b) {
	if(a > b) return a;
	return b;
}
int min(int a,int b) {
	if(a < b) return a;
	return b;
}
struct B {
	int ind;
};
queue<B> qu;
void PFS() {
	int i;
	B a;
	a.ind = s;
	qu.push(a);
	inqueue[s]=1;
	while(!qu.empty()) {
		for(i=0;i<map[qu.front().ind].size();i++) {
			if(min(map[qu.front().ind][i].value,flow[qu.front().ind]) > flow[map[qu.front().ind][i].e]) {
				flow[map[qu.front().ind][i].e]=min(map[qu.front().ind][i].value,flow[qu.front().ind]);
				a.ind = map[qu.front().ind][i].e;
				back[map[qu.front().ind][i].e]=qu.front().ind;
				if(inqueue[map[qu.front().ind][i].e] == 0) {
					qu.push(a);
					inqueue[map[qu.front().ind][i].e]=1;
				}
			}
		}
		inqueue[qu.front().ind]=0;
		qu.pop();
	}
}
void networkflow() {
	vis[s]=1;
	flow[s]=9999999;
	PFS();
}
int main() {
	int a,b,c,i;
	cin>>n>>s>>end;
	while(cin>>a>>b>>c) {
		A d;
		d.e = b;
		d.value = c;
		map[a].push_back(d);
	}
	networkflow();
	cout<<flow[end]<<endl;
	int t=end;
	ans.push_back(end);
	while(back[t] > 0) {
		ans.push_back(back[t]);
		t = back[t];
	}
	for(i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
}