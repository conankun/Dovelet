#include<iostream>
#include<cmath>
using namespace std;
//2 4 8 16 32 64 128 256 512 1024 2048 4096..
int dp[32];
int bits[32];
int n;
int si;
void back(int ind,int sum) {
	int i;
	if(ind == 1) {
		for(i=si;i>=1;i--) {
			if(bits[i] == 0) cout<<4;
			else cout<<7;
		}
	} else {
		int s=0;
		for(i=1;i<ind-1;i++) {
			s+=dp[i];
		}
		if(sum > dp[ind-1]/2) {
			bits[ind-1]=1;
			back(ind-1,sum-dp[ind-2]);
		} else {
			bits[ind-1]=0;
			back(ind-1,sum);
		}
	}
}
int main() {
	int i;
	cin>>n;
	for(i=0;i<=30;i++) {
		dp[i]=pow(2,(double)i);
	}
	int s=n;
	for(i=1;i<=30;i++) {
		if(s-dp[i] <= 0) {
			si = i;
			if(s > dp[i]/2) {
				bits[i]=1;
				back(i,s-dp[i-1]);
			} else {
				bits[i]=0;
				back(i,s);
			}
			break;
		}
		s-=dp[i];
	}
}