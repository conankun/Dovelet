#include<stdio.h>
#define SIZE 1132500
unsigned long long dp[151][SIZE/63+111];
unsigned long long hap[200];
unsigned long long chk[SIZE+111];
unsigned long long score[151];
unsigned long long dpsize[151];
unsigned long long N,K;
int main() {
	scanf("%llu",&N);
	unsigned long long i,j,k;
	for(i=1;i<=N;i++) {
		scanf("%llu",&score[i]);
		score[i]+=score[i-1];
		hap[i]=hap[i-1]+score[i];
	}
	scanf("%llu",&K);
	unsigned long long x,xp,y,yp,size,plus;
	dp[0][1]=1;
	dp[0][1] = dp[0][1]<<63;
	dpsize[0]=1;
	for(i=1;i<=N;i++) {
		for(j=1;j<=i;j++) { //j ~ i 까지 o
			if(j>=2) size=dpsize[j-2];
			else size=1;
			plus=hap[i]-hap[j-1]-score[j-1]*(i-j+1);
			for(k=1;k<=size;k++) {
				x=((k-1)*64+plus)/64+1;
				xp=((k-1)*64+plus)%64;
				y=((k-1)*64+plus+63)/64+1;
				yp=((k-1)*64+plus+63)%64;
				if(j >= 2) {
					dp[i][x]|=dp[j-2][k]>>(yp+1);
					dp[i][y]|=dp[j-2][k]<<(64-xp);
					if(x==y) dp[i][x]|=dp[j-2][k];
					dp[i][k]|=dp[j-2][k];
					if(x > dpsize[i]) dpsize[i]=x;
					if(y > dpsize[i]) dpsize[i]=y;
				} else {
					dp[i][x]|=dp[j-1][k]>>(yp+1);
					dp[i][y]|=dp[j-1][k]<<(64-xp);
					if(x==y) dp[i][x]|=dp[j-1][k];
					dp[i][k]|=dp[j-1][k];
					if(x > dpsize[i]) dpsize[i]=x;
					if(y > dpsize[i]) dpsize[i]=y;
				}
				dp[i][k]|=dp[j][k];
			}
			size=dpsize[j-1];
			for(k=1;k<=size;k++) {
				dp[i][k]|=dp[j-1][k];
				if(k > dpsize[i]) dpsize[i]=k;
			}
		}
	}
	size=dpsize[N];
	unsigned long long bin[100]={0};
	unsigned long long index=0,ind=-1;
	for(i=1;i<=size;i++) {
		index=0;
		unsigned long long m=dp[N][i];
		while(m > 0) {
			bin[++index]=m%2;
			m/=2;
		}
		for(j=64;j>=1;j--) {
			chk[++ind]=bin[j];
			bin[j]=0;
		}
	}
	for(i=0;i<=SIZE;i++) {
		if(i >= K && chk[i]==0) {
			printf("%llu",i);
			return 0;
		}
	}
	printf("%llu",K);
}