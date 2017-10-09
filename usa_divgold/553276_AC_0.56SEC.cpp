#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000
int n,arr[100000],D[1000000];
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) {scanf("%d",&arr[i]);}
	for(i=1;i<1000000;i++) D[i]=-1;
	int mx=0;
	D[0]=1;
	for(i=1;i<=n;i++) {
		for(j=mx;j>=0;j--) {
			if(D[j]>-1) {
				if(D[j+arr[i]] == -1) D[j+arr[i]]=0;
				D[j+arr[i]]+=D[j];
				D[j+arr[i]]%=MOD;
				if(mx<j+arr[i]) mx=j+arr[i];
			}
		}
	}
	int diff=999999999,c=0;
	for(i=0;i<=mx;i++) {
		if(D[i]>-1) {
			if(abs(i-(mx-i)) < diff) {
				c=i;
				diff=abs(i-mx+i);
			}
		}
	}
	printf("%d\n%d",diff,D[c]);
}