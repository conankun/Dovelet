#include<stdio.h>
int n;
int chk[1000001];
int cows[1000000];
int cnt[1000001];
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)  {
		scanf("%d",&cows[i]);
		if(cows[i] != 0) chk[cows[i]]++;
	}
	for(i=1;i<=n;i++) {
		if(cows[i] == 1) continue;
			for(j=2;j*j<=cows[i];j++) {
				if(cows[i]%j==0) {
					if(cows[i]/j != j) chk[cows[i]]+=chk[cows[i]/j];
					chk[cows[i]]+=chk[j];
				}
			}
	}
	for(i=1;i<=n;i++) {
		if(cows[i] == 1) printf("0\n");
		else printf("%d\n",chk[cows[i]]);
	}
}