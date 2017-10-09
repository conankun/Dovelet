#include<stdio.h>
#include<math.h>
int M,N,K;
struct A {
	int x,y,r,b;
}a[100000];
int sum[31111][1111];
int main() {
	scanf("%d %d %d",&M,&N,&K);
	int i,j;
	for(i=1;i<=K;i++) {
		scanf("%d %d %d %d",&a[i].x,&a[i].y,&a[i].r,&a[i].b);
	}
	int mx=0;
	double x1;int x2,tmp;
	for(i=1;i<=M;i++) { //각각의 line 에 대해
		for(j=1;j<=K;j++) {
			if(a[j].y+a[j].r < i || a[j].y-a[j].r > i) continue;
			 x1 = sqrt((double)(a[j].r)*(a[j].r) - (i-a[j].y)*(i-a[j].y))+a[j].x;
			 x2 =  (-1*(int)sqrt((double)(a[j].r)*(a[j].r) - (i-a[j].y)*(i-a[j].y)))+a[j].x;
			if(x1 > x2) {
				tmp=x2;
				x2=x1;
				x1=tmp;
			}
			if(x1!=(int)x1) x1=(int)x1+1;
			if(x1 < 1) x1=1;
			if(x2 > 1000) x2=1000;
			sum[i][(int)x1]+=a[j].b;
			sum[i][x2+1]-=a[j].b;
		}
		for(j=1;j<=N;j++) {
			sum[i][j]+=sum[i][j-1];
			if(sum[i][j] > mx) mx = sum[i][j];
		}
	}
	int count=0;
	for(i=1;i<=M;i++) {
		for(j=1;j<=N;j++) {
			if(mx==sum[i][j]) count++;
		}
	}
	printf("%d\n%d",mx,count);

}