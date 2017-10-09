#include<iostream>
#include<queue>
using namespace std;
int n,k;
int cows[100001];
int isLast[100001];
int vis[100001];
int chk[100001];
int main() {
	scanf("%d%d",&n,&k);
	int i,j;
	for(i=1;i<=n;i++) {
		scanf("%d",&cows[i]);
	}
	int cnt=1;
	int cc=0;
	for(i=1;i<=n;i++) {
		if(vis[cows[i]] != cnt) {
			vis[cows[i]] = cnt;
			cc++;
		}
		if(cc == k) {
			cnt++;
			cc=0;
		}
	}
	cout<<cnt;
}