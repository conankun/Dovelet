#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int n;
int dp[10]={0,1,1,1,4,56,9408,16942080};
int main() {
	cin>>n;
	long long sum=dp[n];
	int i;
	for(i=1;i<=n-1;i++) {
		sum*=i;
	}
	cout<<sum;
}