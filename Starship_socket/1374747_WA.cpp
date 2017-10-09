#include <iostream>
using namespace std;
int N,M;
int main()
{
    scanf("%d%d",&N,&M);
    int i;
    long long sum=0;
    for(i=1;i<=N;i++) {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        sum+=(b-a)*c+d*M;
    }
    cout<<sum;
}
