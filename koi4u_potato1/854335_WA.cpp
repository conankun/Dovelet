#include<stdio.h>
long long ws[211111];
long long wsum[211111];
long long wx[211111];
int n;
int main() {
	scanf("%d",&n);
	int i;
	int x,w;
	for(i=1;i<=n;i++) {
		fscanf(stdin,"%d%d",&x,&w);
		ws[x+100000]+=w;
	}
	
	for(i=0;i<=200005;i++) {
		wsum[i]=wsum[i-1]+ws[i];
		wx[i]=wx[i-1]+i*ws[i];
	}
	long long mn=31000000000111LL,X,KK;
	for(i=0;i<=200005;i++) {
		X=i;
		KK=X*((wsum[i])-(wsum[200005]-wsum[i]))+ wx[200005]-wx[i] - wx[i];
		if(KK < mn) {
			mn = KK;
		}
	}
	printf("%lld",mn);
	
}