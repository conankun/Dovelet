#include<stdio.h>
int n,arr[10000000];
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&arr[i]);
	int s=arr[1],e=2000000000;
	for(i=2;i<=n;i++) {
		if(e>arr[i]) e=arr[i];
		int t=arr[i]*2-e;//시작
		int l=arr[i]*2-s;//끝
		s=t,e=l;
	}
	if(e-s+1<0) printf("0");
	else printf("%d",e-s+1);
}