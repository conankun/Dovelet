#include<iostream>
typedef long long ll;
using namespace std;
ll pow(ll p, ll n, ll k) {
  ll unit = p;
  ll ans = 1;
  for(;n>0;n=n>>1) {
    if(n&1) {
      ans *= unit;
      ans %= k;
    }
    unit *= unit;
    unit %= k;
  }

  return ans;
}
int main() {
    int n;
    scanf("%d",&n);
    while(n--) {
      ll a1,p,q,k,n;
      scanf("%lld%lld%lld%lld%lld",&a1,&p,&q,&k,&n);
      a1 %= k;
      ll pp = pow(p,n,k);
      if (p != 1) printf("%lld\n",(a1*pow(p,n-1,k) + q*((1-pow(p%k,n-1,k))/(1-p%k)) % k) %k);
      else printf("%lld\n",(a1+(n-1)*q)%k);
    }
}
