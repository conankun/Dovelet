#include<stdio.h>
int N;
int cows[10000];
int minus[10000];
int status[10000];
int main() {
	scanf("%d",&N);
	int i,j;
	scanf("\n");
	for(i=1;i<=N;i++) {
		char c;
		scanf("%c\n",&c);
		if(c=='B') cows[i]=1;
		else cows[i]=0;
	}
	int a=0,b=2147483647;
	for(i=1;i<=N;i++) { //사이즈
		int s=0;
		int cnt=0;
		for(j=1;j<=N;j++) {
			if(j-i >= 1) s-=minus[j-i];
			status[j]=(s+cows[j])%2;
			if((s+cows[j])%2==1) {
				if(j+i-1 > N) {
					cnt=100000;
					break;
				}
				minus[j]++;
				s++;
				cnt++;
				status[j]=0;
			}
		}
		for(j=1;j<=N;j++) minus[j]=0;
		if(b>cnt) {
			a=i;
			b=cnt;
		}
	}
	printf("%d %d",a,b);
}