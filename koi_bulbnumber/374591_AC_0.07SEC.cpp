#include<iostream>
using namespace std;
int bulb[100];
int dp[100];
int n,k;
int ans=-1;
string s;
bool t;
void back(int ind,int zan) {
	if(ind == 0) {
		int i;
		for(i=1;i<=n;i++) {
			if(s[i] == 0) s[i]=48;
		}
		t=true;
		return;
	}
	int i;
	int sum=0;
	for(i=0;i<=n;i++) {
		if(bulb[ind] < bulb[i] || i == 0) sum+=dp[i];
		if(sum >= zan && !t) {
			if(bulb[ind] < bulb[i]) s[i]=49;
			back(i,zan-(sum-dp[i]));
			break;
		}
	}
}
int convert() {
	int i;
	int g=1,sum=0;
	for(i=1;i<=n;i++) {
		sum+=(s[i]-48)*g;
		g*=2;
	}
	return sum;
}
int main() {
	int i,j;
	cin>>n;
	s.resize(n+1);
	for(i=n;i>=1;i--) {
		cin>>bulb[i];
	}
	cin>>k;
	int sum=1;
	dp[0]=1;
	for(i=1;i<=n;i++) {
		dp[i]=1;
		for(j=1;j<=i-1;j++) {
			if(bulb[j] > bulb[i]) {
				dp[i]+=dp[j];
			}
		}
		sum+=dp[i];
		if(sum >= k) {
			//역추적.
			s[i]=49;
			back(i,k-(sum-dp[i]));
			ans = convert();
			break;
		}
	}
	if(k == 0) ans=0;
	cout<<ans;
}