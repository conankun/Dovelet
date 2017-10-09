#include<stdio.h>
int main(){
int n,l,m,ans=0;
scanf("%d%d",&n,&l);
int i;
for(i=1;i<=n;i++) {
scanf("%d",&m);
if(l-(m%l) > ans && l-(m%i) != l) {
ans=l-(m%l);
}
}
printf("%d",ans);
}