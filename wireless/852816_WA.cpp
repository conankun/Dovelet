#include<stdio.h>
#include<math.h>
struct A {
	int x1,y1,r,b;
};
int M,N,K;
A a[100000];
int sum[31000][1100];
int main() {
	scanf("%d%d%d",&M,&N,&K);
	int i,j;
	for(i=1;i<=K;i++) {
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].r,&a[i].b);
	}
	for(i=1;i<=K;i++) {
		for(j=1;j<=M;j++) {
			//(x-x1)^2 = r^2-(y-j)^2
			if(a[i].r + a[i].y1 < j || a[i].y1-a[i].r > j) continue;
			double x1=sqrt((double)(a[i].r*a[i].r-(a[i].y1-i)*(a[i].y1-j)))+a[i].x1;
			double x2=(-1*sqrt((double)(a[i].r*a[i].r-(a[i].y1-i)*(a[i].y1-j))))+a[i].x1;
			//
			if(fabs(x1-(int)x1) < 0.00000000001) {}
			else x1=(int)x1+1;
			//
			if(fabs(x2-(int)x2) < 0.00000000001) {}
			else x2=(int)x2+1;
			//
			if(x1 > x2) {
				int tmp=x2;
				x2=x1;
				x1=tmp;
			}
			sum[j][(int)x1]+=a[i].b;
			sum[j][(int)x2+1]-=a[i].b;
		}
	}
	int mx=0;
	for(i=1;i<=M;i++) {
		for(j=1;j<=N;j++) {
			sum[i][j]=sum[i][j-1]+sum[i][j];
			if(mx < sum[i][j]) mx=sum[i][j];
		}
	}
	int count=0;
	for(i=1;i<=M;i++) {
		for(j=1;j<=N;j++) {
			if(sum[i][j]==mx) count++;
		}
	}
	printf("%d\n%d",mx,count);
}