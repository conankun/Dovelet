#include<stdio.h>
int C,N;
int main() {
	int i,j,d;
	scanf("%d",&C);
	for(d=1;d<=C;d++) {
		scanf("%d",&N);
		int mn=2147483647;
		for(i=1;i<=N;i++) {
			for(j=1;j<=N;j++) {
				if(N%(i*j)==0) {
					int z = N/(i*j);
					if(i*j*2+j*z*2+i*z*2 < mn) {
						mn = i*j*2+j*z*2+i*z*2;
					}
				}
			}
		}
		printf("%d\n",mn);
	}
}