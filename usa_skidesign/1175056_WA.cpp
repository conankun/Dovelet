#include<stdio.h>
int N;
int hill[10000];
int change[10000];
int abs(int x) {
	if(x < 0) return -1*x;
	return x;
}
int main() {
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	int i;
	scanf("%d",&N);
	for(i=1;i<=N;i++) {
		scanf("%d",&hill[i]);
	}
	
	long long cost=-1;
	int j;

	for(i=1;i<=100;i++) { // set minimum
		//set the values less than i to i and more than i+17 to i+17
		for(j=1;j<=N;j++) {
			change[j]=0;
			if(hill[j] < i) {
				change[j] = i-hill[j];
			}
			if(hill[j] > i+17) {
				change[j] = hill[j]-(i+17);
			}
		}
		long long tmp=0;
		for(j=1;j<=N;j++) tmp += change[j]*change[j];
		if(tmp < cost || cost == -1) cost = tmp;
	}
	

	printf("%lld",cost);

}