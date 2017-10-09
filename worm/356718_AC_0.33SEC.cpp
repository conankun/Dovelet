#include<iostream>
using namespace std;
int a,b,d,n;
int dp[1000010];
int born[1000010];
int ss[1000010];
int i;
int main() {
	cin>>a>>b>>d>>n;
	born[0]=1;
	for(i=0;i<=a-1;i++) {
		dp[i]=1;
	}
	//어제있던 마릿수+오늘 태어난 마릿수-d일전 태어난 마릿수
	//오늘의 성체수 = 어제성체수+a전날 태어난 짚신벌레수-b일전 태어난 짚신벌레수
	//dp[i] = dp[i-1]+born[i]-born[i-d];
	//ss[i] = ss[i-1]+born[i-a]-born[i-b];
	dp[a]=2;
	ss[a]=1;
	born[a]=1;
	for(i=a+1;i<=n;i++) {
		ss[i] = (ss[i-1]+born[i-a]+1000-born[i-b])%1000;
		dp[i] = (dp[i-1]+ss[i]+1000-born[i-d])%1000;
		born[i] = ss[i];
	}
	cout<<dp[n];
}