#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int n,A[1000],B[1000];
int main() {
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++) {
		scanf("%d",&A[i]);
		A[i]+=10000;
		B[i]=A[i];
	}
	bool t=true;
	while(t) {
		t=false;
		for(i=2;i<=n-1;i++) {
			if(B[i-1]<B[i]&&B[i+1]<B[i]) {
				B[i]--;
				t=true;
				break;
			}
			if(B[i-1]>B[i]&&B[i+1]>B[i]) {
				B[i]++;
				t=true;
				break;
			}
		}
	}
	int V=abs(A[1]-B[1]);;
	for(i=2;i<=n;i++) {
		V+=abs(B[i]-B[i-1]);
		V+=abs(A[i]-B[i]);
	}
	printf("%d",V);
}