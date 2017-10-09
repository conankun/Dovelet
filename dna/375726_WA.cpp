#include<iostream>
#include<string>
using namespace std;
int n;
string dna[1000];
bool vis[1000];
int mn=99999999;
void dfs(int ind,string s) {
	int i,j,k;
	bool tr=true;
	for(i=1;i<=n;i++) {
		if(!vis[i]) {
			tr=false;
			break;
		}
	}
	if(tr) {
		if(s.size() < mn) {
			mn = s.size();
		}
	} else {
		vis[i]=1;
		dfs(i,s+dna[i]);
		vis[i]=0;
		for(i=1;i<=n;i++) {
			if(vis[i]) continue;
			else {
				int mx=0;
				for(j=1;j<dna[i].size();j++) {
					int cc=0;
					bool t=1;
					for(k=s.size()-j;k<s.size();k++) {
						if(s[k] != dna[i][cc]) {
							t=0;
							break;
						}
						cc++;
					}
					if(t) {
						vis[i]=1;
						string imsi=s;
						for(k=j;k<dna[i].size();k++) {
							imsi+=dna[i][k];
						}
						dfs(i,imsi);
						vis[i]=0;
					}
				}
			}
		}
	}
}
int main() {
	cin>>n;
	int i;
	for(i=1;i<=n;i++) cin>>dna[i];
	for(i=1;i<=n;i++) {
		vis[i]=1;
		dfs(i,dna[i]);
		vis[i]=0;
	}
	cout<<mn;
}