#include<stdio.h>
int max(int a,int b){if(a>b) return a; return b;}
int main() {
	int A,B,C,N;
	scanf("%d %d %d %d",&A,&B,&C,&N);
	int i;
	int s=0;
	for(i=1;i<=N;i++) {
		s+=max(max(A,B),C);
		if(max(max(A,B),C) == A && A!=0) A--;
		else if(max(max(A,B),C) == B && B!=0) B--;
		else if(C!=0) C--;
	}
	printf("%d",s);
}