#include <iostream>
using namespace std;
int ch[1111111];
int tree[1111111];
int dp[1111111];
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++) scanf("%d",&ch[i]);
    int size=1;
    for(;size<n;size*=2);
    int ans=0;
    for(i=1;i<=n;i++) {
        int ls=size+1,rs=size+ch[i];
        bool ok=true;
        int mx=0;
        while(ls<=rs&&ok) {
            if(ls==rs) ok=false;
            if(ls%2==1) {
                if(mx < tree[ls]) mx = tree[ls];
                ls++;
            }
            if(rs%2==0) {
                if(mx < tree[rs]) mx=tree[rs];
                rs--;
            }
            ls/=2;
            rs/=2;
        }
        dp[i] = mx+1;
        rs=size+ch[i];
        while(rs>0) {
            if(tree[rs] < dp[i]) tree[rs]=dp[i];
            rs/=2;
        }
        if(dp[i] > ans) ans=dp[i];
    }
    cout<<n-ans;
}
