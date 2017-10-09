#include<iostream>
#include<string>
using namespace std;
string s;
int n;
int mx=0;
void neck(int ind) {
	int i;
	if(ind > n) return;
	else {
		int vis[1000]={0};
		int ss,e;
		if(ind == n) ss = 1;
		else ss = ind+1;
		e = ind;
		char color = s[ind];
		int cnt=0;
		bool t=false;
		for(i=e;i>=1;i--){
			if((s[i] == color || s[i] == 'w') && vis[i] == 0) {
				cnt++;
				vis[i]=1;
			}
			else if(color == 'w' && s[i] != 'w' && vis[i] == 0) {
				if(vis[i] == 0) cnt++;
				vis[i]=1;
				color = s[i];
			}
			else break;
			if(i == 1) t=true;
		}
		for(i=n;i>e;i--) {
			if(!t) break;
			if((s[i] == color || s[i] == 'w') && vis[i] == 0) {
				cnt++;
				vis[i]=1;
			}
			else if(color == 'w' && s[i] != 'w' && vis[i] == 0) {
				if(vis[i] == 0) cnt++;
				vis[i]=1;
				color = s[i];
			}
			else break;
		}
		t=false;
		color = s[ss];
		for(i=ss;i<=n;i++) {
			if((s[i] == color || s[i] == 'w') && vis[i] == 0) {
				cnt++;
				vis[i]=1;
			}
			else if(color == 'w' && s[i] != 'w' && vis[i] == 0) {
				if(vis[i] == 0) cnt++;
				vis[i]=1;
				color = s[i];
			}
			else break;
			if(i == n) t=true;
		}
		for(i=1;i<ss;i++) {
			if(!t) break;
			if((s[i] == color || s[i] == 'w') && vis[i] == 0) {
				cnt++;
				vis[i]=1;
			}
			else if(color == 'w' && s[i] != 'w' && vis[i] == 0) {
				if(vis[i] == 0) cnt++;
				vis[i]=1;
				color = s[i];
			}
			else break;
		}
		if(cnt > mx) {
			mx = cnt;
		}
		neck(ind+1);
	}
}
int main() {
	cin>>n;
	int i;
	s.resize(n*2);
	for(i=1;i<=n;i++) cin>>s[i];
	neck(1);
	cout<<mx;
}