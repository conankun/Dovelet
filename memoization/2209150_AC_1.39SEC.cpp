#include<iostream>
using namespace std;
long long k;
struct A {
  long long a,b;
  long long c,d;
  A operator * (const A &ab) const {
    A aa = {0,0,0,0};
    aa.a = (a * ab.a)%k + (b * ab.c)%k;
    aa.a %= k;
    aa.b = (a * ab.b)%k + (b * ab.d)%k;
    aa.b %= k;
    aa.c = (c * ab.a)%k + (d * ab.c)%k;
    aa.c %= k;
    aa.d = (c * ab.b)%k + (d * ab.d)%k;
    aa.d %= k;
    return aa;
  }
};
int main() {
  int Q;
  long long a1,p,q,n;
  scanf("%d",&Q);
  while(Q--) {
    scanf("%lld%lld%lld%lld%lld",&a1,&p,&q,&k,&n);
    A a = {1,0,0,1};
    A unit = {p,1,0,1};
    n = n-1;
    for(;n>0;n=n>>1) {
      if((n&1)==1) {
        a = unit * a;
      }
      unit = unit * unit;
    }
    long long ans = (a.a * a1)%k + (a.b * q)%k;
    ans %= k;
    printf("%lld\n",ans);
  }
}
