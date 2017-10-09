#include<stdio.h>
int x[3111111],w[3111111];
long long ws[211111];
long long wsum[211111];
long long wx[211111];
int n;
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		fscanf(stdin,"%d%d",&x[i],&w[i]);
	}
	for(i=1;i<=n;i++) ws[x[i]+100000]+=w[i];
	
	for(i=0;i<=200001;i++) {
		wsum[i]=wsum[i-1]+ws[i];
		wx[i]=wx[i-1]+i*ws[i];
	}
	long long mn=31000000000111LL;
	for(i=0;i<=200001;i++) {
		long long X=i;
		if(X*((wsum[i])-(wsum[200001]-wsum[i]))+ wx[200001]-wx[i] - wx[i] < mn) {
			mn = X*((wsum[i])-(wsum[200001]-wsum[i]))+ wx[200001]-wx[i] - wx[i];
		}
	}
	printf("%lld",mn);
	
}