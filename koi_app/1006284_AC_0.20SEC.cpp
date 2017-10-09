#include <iostream>
using namespace std;
int N,M;
int m[1000];
int c[1111];
int cost[111111];
int main()
{
    int sum=0;
    int i,j;
    cin>>N>>M;
    for(i=1;i<=N;i++) {
        cin>>m[i];
    }
    for(i=1;i<=N;i++) {
        cin>>c[i];
        sum+=c[i];
    }
    for(i=1;i<=10000;i++) {
        cost[i]=-1;
    }
    for(i=1;i<=N;i++) {
        for(j=sum;j>=0;j--) {
            if(cost[j]!=-1) {
                cost[j+c[i]] = max(cost[j+c[i]],cost[j]+m[i]);
            }
        }
    }
    int x=-1;
    for(i=0;i<=10000;i++) {
        if(cost[i] >= M) {
            if(x==-1 || i < x) {
                x=i;
            }
        }
    }
    cout<<x;
}
