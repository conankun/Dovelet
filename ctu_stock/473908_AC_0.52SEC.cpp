#include<stdio.h>
int D,M;
int P[100000];
int mx[100000];
int main() {
	scanf("%d%d",&D,&M);
	int i;
	for(i=1;i<=D;i++) scanf("%d",&P[i]);
	int _max=0;
	for(i=D;i>=1;i--) {
		mx[i] = _max;
		if(_max < P[i]) _max=P[i];
	}
	int ans=0;
	for(i=1;i<=D;i++) {
		if(((M/P[i])*mx[i])-((M/P[i])*P[i]) > ans) ans = ((M/P[i])*mx[i])-((M/P[i])*P[i]);
	}
	printf("%d",ans);
}