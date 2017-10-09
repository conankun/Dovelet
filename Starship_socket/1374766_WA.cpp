#include <iostream>
#include<algorithm>

using namespace std;
long long N,M;
struct A {
    long long a,b,c,d;
    bool operator<(const A &aa) const {
        return a < aa.a;
    }
}arr[1000000];
long long min(long long A, long long B) {
    if(A > B) return B;
    return A;
}
long long abs_f(long long aa) {
    if(aa < 0) return 0;
    return aa;
}
int main()
{
    scanf("%lld%lld",&N,&M);
    int i;
    long long sum=0;
    for(i=1;i<=N;i++) {
        scanf("%lld%lld%lld%lld",&arr[i].a,&arr[i].b,&arr[i].c,&arr[i].d);
       // sum+=(arr[i].b-arr[i].a)*arr[i].c+arr[i].d*M;
    }
    sort(arr+1,arr+1+N);
    for(i=1;i<=N;i++) {
        sum+=(arr[i].b-arr[i].a)*arr[i].c+arr[i].d*min(M,abs_f(arr[i+1].a-arr[i].b));
    }
    cout<<sum;
}
