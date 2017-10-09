#include<stdio.h>
int n,A[10000000],i,s=A[1],e=2000000000,t,l;
int main() {scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=2;i<=n;i++) {if(e>A[i]) e=A[i];t=A[i]*2-e;l=A[i]*2-s;s=t,e=l;}if(e-s+1<0) printf("0");else printf("%d",e-s+1);}