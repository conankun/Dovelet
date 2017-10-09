#include<stdio.h>
int fills[111111];
int main() {
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) {
		int a,b;
		int c,d;
		scanf("%d%d",&a,&b);
		c=a%100;a/=100;
		d=b%100;b/=100;
		int x=a*60+c;
		int y=b*60+d;
		x-=10;
		y+=10;
		if(x < 600) x=0;
		if(y>1320) y=1320;
		for(j=x;j<=y;j++) fills[j]=1;
	}
	int sum=0,mx=0;
	for(i=600;i<=1320;i++) {
		if(fills[i]==0) {
			sum++;
			if(sum > mx) mx=sum;
		}else sum=0;
	}
	printf("%d",mx+1);
}