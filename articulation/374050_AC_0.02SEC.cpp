#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int n;
int visit;
int vis[1000];
int map[1000][1000];
int chk[1000];
bool ap[1000];
int child;
int dfs(int ind) {
	vis[ind]=1;
	chk[ind]=++visit;
	int mn=visit;
	int i;
	for(i=1;i<=n;i++) {
		if(map[ind][i] == 1) {
			if(vis[i]==0) {
				vis[i]=1;
				int x = dfs(i);
				if(x < mn) mn=x;
				if(ind == 1) child++;
				if(x >= chk[ind] && ind != 1) ap[ind]=1;
			} else if(mn > chk[i]) mn = chk[i];
		}
	}
	return mn;
}
int main() {
	int i;
	cin>>n;
	string s;
	cin.get();
	while(getline(cin,s)) {
		int num;
		istringstream in(s);
		in>>num;
		int a;
		while(in>>a) {
			map[num][a]=1;
			map[a][num]=1;
		} 
	}
	dfs(1);
	if(child >= 2) ap[1]=1;
	for(i=1;i<=n;i++) {
		if(ap[i]) cout<<i<<" ";
	}
}