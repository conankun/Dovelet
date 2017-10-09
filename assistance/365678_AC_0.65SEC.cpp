#include<iostream>
using namespace std;
int vis[100001];
int n;
int main() {
	cin>>n;
	int i,j;
	int cnt=0;
	for(i=4;i<=33809;i+=2) {
		vis[i]=-1;
	}
	for(i=3;i<=33809;i+=2) {
		if(vis[i] != 0) continue;
		int cnt=0;
		for(j=i+1;j<=33809;j++) {
			if(vis[j] == 0) cnt++;
			if(cnt == i) {
				vis[j]=-1;
				cnt=0;
			}
		}
	}
	cnt=0;
	for(i=2;i<=33809;i++) {
		if(vis[i] == 0) {
			cnt++;
		}
		if(cnt == n) {
			cout<<i;
			break;
		}
	}
}