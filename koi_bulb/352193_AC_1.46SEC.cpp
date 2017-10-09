#include<iostream>
#include<algorithm>
using namespace std;
int switchs[10000]={0};
int bulbindex[10000]={0};
int bulb[10000]={0};
int back[10000]={0};
int bt[10000]={0};
int btindex=0;
int dp[10000]={0};
int n;
int main() {
	cin>>n;
	for(int i=0;i<n;i++) cin>>switchs[i];
	for(int i=0;i<n;i++) cin>>bulb[i];
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(bulb[j] == switchs[i]) {
				bulbindex[i] = j;
				break;
			}
		}
	}
	int mxvalue=0;
	int mxindex=0;;
	for(int i=0;i<n;i++) {
		int mx=0;
		int bt=-1;
		for(int j=i-1;j>=0;j--) {
			if(bulbindex[j] < bulbindex[i] && dp[j] > mx) {
				mx = dp[j];
				bt = j;
			}
		}
		dp[i] = mx+1;
		back[i]=bt;
		if(dp[i] > mxvalue) {
			mxvalue = dp[i];
			mxindex = i;
		}
	}
	cout<<mxvalue<<endl;
	int t = mxindex;
	bt[btindex++] = switchs[mxindex];
	while(back[t] != -1) {
		bt[btindex++] = switchs[back[t]];
		t = back[t];
	}
	sort(bt,bt+btindex);
	for(int i=0;i<btindex;i++) cout<<bt[i]<<" ";
}