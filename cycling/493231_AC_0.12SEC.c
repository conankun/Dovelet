#include<stdio.h>
int a,b,c,i,n,mx;
int main() {
scanf("%d",&n);scanf("%d",&a);b=a;
for(i=2;i<=n;i++) {
scanf("%d",&a);
if(a>c) {
if(mx<a-b) mx=a-b;
} else b=a;c=a;
}
printf("%d",mx);
}