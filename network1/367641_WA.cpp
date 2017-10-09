#include<iostream>
using namespace std;
int n;
int map[1000][1000];
int vis[1000];
int vis2[1000];
int cnt;
void dfs(int ind,int code) {
	int i;
	vis[ind]=code;
	for(i=1;i<=n;i++) {
		if(vis[i] != code && map[ind][i] == 1) {
			vis[i]=code;
			dfs(i,code);
		}
	}
}
int main() {
	int i;
	cin>>n;
	for(i=1;i<=n;i++) {
		int a;
		while(cin>>a) {
			if(a == 0) break;
			else map[i][a]=1;
		}
	}
	for(i=1;i<=n;i++) dfs(i,i);
	for(i=1;i<=n;i++) {
		if(vis2[vis[i]] == 0) {
			vis2[vis[i]]=1;
			cnt++;
		}
	}
	cout<<cnt;
}