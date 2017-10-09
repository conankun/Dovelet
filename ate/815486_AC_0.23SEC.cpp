#include<stdio.h>
int main() {
	int N;
	scanf("%d",&N);
	int i,j,cnt=0;
	for(i=1;i<=99;i++) {
		for(j=1;j<=99;j++) {
			if(N-i-j==0) cnt++;
		}
	}
	printf("%d",cnt);
}