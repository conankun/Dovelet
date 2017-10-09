#include <iostream>
using namespace std;
int ch[1111111];
int chk[1111111];
int dp[1111111];
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++) {
        scanf("%d",&ch[i]);
        chk[ch[i]]=i;
    }
    int mx=0;
    for(i=1;i<=n;i++) {
        if(chk[ch[i]-1] < i) dp[i]=dp[chk[ch[i]-1]]+1;
        else dp[i]=1;
        if(dp[i] > mx) mx = dp[i];
    }
    cout<<n-mx;
}
