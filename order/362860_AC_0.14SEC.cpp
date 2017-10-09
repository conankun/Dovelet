#include<iostream>
using namespace std;
int n,r,p,q;
int vis[100];
char s1[100];
int cnt=0;
bool t=false;
void dfs(int ind,int c) {
	int i;
	if(c == r) {
		cnt++;
		if(cnt == p) {
			//출력.
			for(i=1;i<=r;i++) cout<<s1[i];
			cout<<endl;
			t=true;
			return;
		}
	} else {
		for(i=0;i<n;i++) {
			if(vis[i] == 0) {
				vis[i]=1;
				s1[c+1]=i+'A';
				dfs(i,c+1);
				vis[i]=0;
			}
		}
	}
}
void dfs2(int ind,int c) {
	int i;
	if(c == r) {
		cnt++;
		if(cnt == q) {
			//출력.
			for(i=1;i<=r;i++) cout<<s1[i];
			cout<<endl;
			t=true;
			return;
		}
	} else {
		for(i=ind+1;i<n;i++) {
			if(vis[i] == 0) {
				vis[i]=1;
				s1[c+1]=i+'A';
				dfs2(i,c+1);
				vis[i]=0;
			}
		}
	}
}
int main() {
	int i;
	cin>>n>>r>>p>>q;
	dfs(0,0);
	cnt=0;
	for(i=1;i<=n;i++) vis[i]=0;
	dfs2(-1,0);
}