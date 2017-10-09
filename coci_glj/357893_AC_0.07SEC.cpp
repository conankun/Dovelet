#include<iostream>
#include<stdlib.h>
using namespace std;
int d[11];
int dp[11];
int i;
int main() {
for(i=1;i<=10;i++) cin>>d[i];
int min=9999;
for(i=1;i<=10;i++) {
dp[i] = dp[i-1]+d[i];
if(abs(100-dp[i]) <= abs(100-min)) {
min = dp[i];
}
}
cout<<min;
}