#include<iostream>
#include<algorithm>
using namespace std;
int index1[1000];
int index2[1000];
int vis[1000];
int main() {
	int n,s,r;
	cin>>n>>s>>r;
	int i;
	for(i=0;i<s;i++) cin>>index1[i];
	for(i=0;i<r;i++) {
		cin>>index2[i];
		vis[index2[i]]=1;
	}
	sort(index1,index1+s);
	sort(index2,index2+r);
	for(i=1;i<=n;i++) vis[i]=1;
	for(i=0;i<s;i++) vis[index1[i]]=0;
	vis[0]=1;
	for(i=0;i<s;i++) {
		if(vis[index2[i]-1] == 0) {
			vis[index2[i]-1]=1;
		} else if(vis[index2[i]+1] == 0) {
			vis[index2[i]+1]=1;
		}
	}
	int cnt=0;
	for(i=1;i<=n;i++) {
		if(vis[i] == 0) cnt++;
	}
	cout<<cnt;
}