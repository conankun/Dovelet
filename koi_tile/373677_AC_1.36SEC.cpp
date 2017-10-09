#include<iostream>
using namespace std;
struct A {
	int cnt;
	int value;
};
int n;
int chk[3000000];
int data[10000];
A dp[3010][3010];
int main() {
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) {
		cin>>data[i];
		chk[data[i]]=i;
	}
	int mx=0;
	for(i=1;i<=n;i++) {
		dp[i][i].cnt=1;
		dp[i][i].value = data[i];
		for(j=i+1;j<=n;j++) {
			int cha = data[j]-data[i];
			int d;
			int cnt=0;
			if(data[i]-cha <= 0) {
				cnt=dp[i][i].cnt;
				d=dp[i][i].value;
			} else if(chk[data[i]-cha] == 0) {
				cnt=dp[i][i].cnt;
				d=dp[i][i].value;
			} else {
				cnt = dp[chk[data[i]-cha]][i].cnt;
				d=dp[chk[data[i]-cha]][i].value;
			}
			dp[i][j].value = d+data[j];
			dp[i][j].cnt = cnt+1;
			if(cnt+1 >= 3 && mx < dp[i][j].value) {
				mx = dp[i][j].value;
			}
		}
	}
	cout<<mx;
}