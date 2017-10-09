#include<stdio.h>
int a,b=100000,c,i,n,mx;
int main() {
scanf("%d",&n);
for(i=1;i<=n;i++) {
scanf("%d",&a);
if(a>b) {
if(mx<a-b) mx=a-b;
} else b=a;
}
printf("%d",mx);
}