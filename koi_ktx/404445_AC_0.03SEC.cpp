#include<iostream>
#include<algorithm>
using namespace std;
struct A {
	int s,e;
	bool operator<(const A &a) const {
		return e < a.e;
	}
};
int n;
A ktx[1000000];
int dp[1000000];
int index=0;
void bs(int low,int high,int root) {
	int mid = (low+high)/2;
	if(low > high) return;
	if(!(ktx[mid].e >= ktx[root].s && ktx[mid].e <= ktx[root].e)) {
		if(index < mid) index = mid;
		bs(mid+1,high,root);
	} else {
		bs(low,mid-1,root);
	}
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d%d",&ktx[i].s,&ktx[i].e);
	sort(ktx+1,ktx+1+n);
	dp[0]=1;
	for(i=1;i<=n;i++) {
		index=0;
		bs(1,i-1,i);
		dp[i] = dp[i-1]+dp[index];
		dp[i]%=20070713;
	}
	printf("%d",dp[n]);
}