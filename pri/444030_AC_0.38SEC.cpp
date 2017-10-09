#include<stdio.h>
int isPrime[5000001];
int main() {
	int i,j;
	for(i=2;i<=5000000;i++) {
		isPrime[i]=1;
	}
	for(i=2;i<=5000000;i++) {
		if(!isPrime[i]) continue;
		for(j=2*i;j<=5000000;j+=i) {
			isPrime[j]=0;
		}
	}
	for(i=2;i<=5000000;i++) {
		if(isPrime[i]) printf("%d\n",i);
	}
}