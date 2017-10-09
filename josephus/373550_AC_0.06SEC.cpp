#include<iostream>
using namespace std;
int n,m,k;
int vis[10000];
int main() {
	int i,j;
	cin>>n>>m>>k;
	cout<<m<<" ";
	vis[m]=1;
	int cnt=0;
	int last=m;
	for(i=0;i<n-1;i++) {
		cnt=0;
		if(m == n) m = 0;
		for(j=m+1;j<=n;j++) {
			if(vis[j] == 0) cnt++;
			if(cnt == k) {
				cout<<j<<" ";
				vis[j]=1;
				m=j;
				break;
			}
			if(j == n) {
				j=0;
			}
		}
	}
}