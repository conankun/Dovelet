#include<stdio.h>
int a,b,c,i,n,mx;
int main() {
scanf("%d",&n);
scanf("%d",&a);
for(i=1;i<=n;i++) {
if(a>b) {
if(mx>b-a) mx=b-a;
} else b=a;
}
printf("%d",mx);
}