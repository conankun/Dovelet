#include<stdio.h>
int n;
int chk[100111];
int cows[100111];
int cnt[100111];
FILE *in = stdin;
FILE *out = stdout;
int main() {
	fscanf(in,"%d",&n);
	int i,j;
	bool t=false;
	for(i=1;i<=n;i++)  {
		fscanf(in,"%d",&cows[i]);
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
		 fprintf(out,"%d\n",chk[cows[i]]-1);
	}
}