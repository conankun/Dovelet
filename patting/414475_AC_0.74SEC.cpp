#include<stdio.h>
int n;
int chk[1000001];
int cows[1000000];
int cnt[1000001];
int main() {
	scanf("%d",&n);
	int i,j;
	bool t=false;
	for(i=1;i<=n;i++)  {
		scanf("%d",&cows[i]);
		cnt[cows[i]]++;
	}
	for(i=1;i<=n;i++) {
		if(chk[cows[i]] > 0) continue;
			for(j=1;j*j<=cows[i];j++) {
				if(cows[i]%j==0) {
					if(cows[i]/j != j) chk[cows[i]]+=cnt[cows[i]/j];
					chk[cows[i]]+=cnt[j];
				}
			}
	}
	for(i=1;i<=n;i++) {
		 printf("%d\n",chk[cows[i]]-1);
	}
}