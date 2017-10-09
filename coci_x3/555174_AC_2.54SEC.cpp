#include<stdio.h>
long long sum[1111111][32];
long long con[1111111][32];
long long N;
long long arr[1111111];
long long sums=0;
void convert(long long m,long long index) {
	long long imsi[30]={};
	long long a=0;
	while(m>0) {
		con[index][++a]=m%2;
		m/=2;
	}
	long long i;
	for(i=1;i<=30;i++) {
		sum[index][i]=con[index][i]+sum[index+1][i];
	}
}
long long abc[99];
int main() {
	scanf("%lld",&N);
	long long i,j;
	for(i=1;i<=N;i++) scanf("%lld",&arr[i]);
	for(i=N;i>=1;i--) {
		convert(arr[i],i);
	}
	for(i=1;i<=N-1;i++) {
		//n-i
		for(j=1;j<=30;j++) {
			if(con[i][j]==0) {
				abc[j]=sum[i+1][j];
			} else {
				abc[j]=N-i-sum[i+1][j];
			}
		}
		long long g=1;
		for(j=1;j<=30;j++) {
			sums+=g*abc[j];
			g*=2;
		}
	}
	 printf("%lld",sums);
}