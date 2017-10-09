#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#define maxn 210
#define maxm 100010
using namespace std;
typedef long long LL;
bool awal=true;
struct Node
{
    LL S,G;
    int id;
    Node() {}
    Node(LL S,LL G,int id): S(S),G(G),id(id) {}
};
int pre[maxn][maxm],a[maxm],n,m;
LL sum[maxm],dp[maxm];
void read()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
        sum[i]=sum[i-1]+a[i];
    }
}
void print(int n,int m)
{
    if(n==0) return;
    print(n-1,pre[n][m]);
    if(awal==true) { awal=false; printf("%d",pre[n][m]); }
    else printf(" %d", pre[n][m]);
}
void Dp()
{
    static Node queue[maxm];
    for(int i=1;i<=m;++i)
    {
        int front=1,rear=1;
        queue[rear]=Node(dp[i]-sum[i]*sum[i],sum[i],i);
        for(int j=i+1;j<=n;++j)
        {
            while(front<rear&&queue[front].S+sum[j]*queue[front].G<=queue[front+1].S+sum[j]*queue[front+1].G)
                ++front;
            Node now(dp[j]-sum[j]*sum[j],sum[j],j);
            dp[j]=queue[front].S+sum[j]*queue[front].G;
            pre[i][j]=queue[front].id;
            while(front<rear&&(now.S-queue[rear].S)*(queue[rear].G-queue[rear-1].G)>=(queue[rear].S-queue[rear-1].S)*(now.G-queue[rear].G))
                --rear;
            queue[++rear]=now;
        }
    }
    cout<<dp[n]<<endl;
    print(m,n);
}
int main()
{
    read();
    Dp();
}