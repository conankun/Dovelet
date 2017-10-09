#include<stdio.h>
int d[1011],S,T[1011],F[1011],N,H[1011],D[1011],M;
int main() {
	scanf("%d%d",&N,&S);
	int i,j;
	for(i=1;i<=N;i++) {
		scanf("%d%d",&T[i],&F[i]);
		H[i]=H[i-1]+T[i];
		D[i]=D[i-1]+F[i];
	}
	for(i=N;i>=1;i--) {
		M=2147483647;
		for(j=N+1;j>i;j--) {
			if(M>(S+H[j-1]-H[i-1])*(D[N]-D[i-1])+d[j])M=(S+H[j-1]-H[i-1])*(D[N]-D[i-1])+d[j]; 
		}
		d[i]=M;
	}
	printf("%d",d[1]);
}