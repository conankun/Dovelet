#include<stdio.h>
long long X[1000001],D[1000001],Q[1000003],A,B,C,N,h=1,t=2;
long long f(long long i) {return 2*X[i];}long long s(long long i) {return X[i];}
long long g(long long j,long long k) {return s(j)+s(k)-(D[k]-D[j]+B*(s(j)-s(k)))/(A*(s(j)-s(k)));}
int main() {scanf("%lld%lld%lld%lld",&N,&A,&B,&C);long long i,j;for(i=1;i<=N;i++){scanf("%lld",&X[i]);X[i]+=X[i-1];}for(i=1;i<=N;i++) {for(j=h;j<t-1;j++){if(g(Q[j+1],Q[j]) < f(i)) h++;else break;}D[i] = A*(X[i]-X[Q[h]])*(X[i]-X[Q[h]])+B*(X[i]-X[Q[h]])+C+D[Q[h]];for(j=t-1;j>h;j--) {if(g(i,Q[j]) < g(Q[j],Q[j-1])) t--;else break;}Q[t++] = i;}printf("%lld",D[N]);}