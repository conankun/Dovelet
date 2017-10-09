#include <iostream>
#include<algorithm>

using namespace std;
int N,M;
struct A {
    int a,b,c,d;
    bool operator<(const A &aa) const {
        return a < aa.a;
    }
}arr[1000000];
int main()
{
    scanf("%d%d",&N,&M);
    int i;
    long long sum=0;
    for(i=1;i<=N;i++) {
        scanf("%d%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c,&arr[i].d);
       // sum+=(arr[i].b-arr[i].a)*arr[i].c+arr[i].d*M;
    }
    sort(arr+1,arr+1+N);
    for(i=1;i<=N;i++) {
        sum+=(arr[i].b-arr[i].a)*arr[i].c+arr[i].d*min(M,abs(arr[i+1].a-arr[i].b));
    }
    cout<<sum;
}
