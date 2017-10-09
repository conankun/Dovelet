#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n,m;
int cnt=0;
vector<int> map[50010];
int vis[50010];
queue<int> qu;
void BFS(int start) {
	int i;
	qu.push(start);
	while(!qu.empty()) {
		vis[qu.front()]=1;
		for(i=0;i<map[qu.front()].size();i++) {
			if(vis[map[qu.front()][i]] == 0) {
				vis[map[qu.front()][i]]=1;
				qu.push(map[qu.front()][i]);
			}
		}
		qu.pop();
	}
	cnt++;
}
int main() {
	scanf("%d %d",&n,&m);
	int i,j;
	for(i=0;i<m;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	for(i=1;i<=n;i++) {
		if(vis[i] == 0) {
			BFS(i);
		}
	}
	cout<<cnt;
}