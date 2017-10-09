#include<stdio.h>
#include<queue>
using namespace std;
int B[2000];
int C[2000];
int A[30000];
int counts;
int M,N;
int main() {
	scanf("%d%d",&M,&N);
	int i,j;
	for(i=1;i<=N;i++) {
		scanf("%d",&A[i]);
	}
	int cnt=0;
	if(A[1]<A[2]) cnt=1;
	B[A[1]]++;
	C[A[2]]++;
	for(i=2;i<=N/2;i++) {
		B[A[i]]++;
		C[A[i]]--;
		C[A[i+i-1]]++;
		C[A[i+i]]++;
		int D[1005]={0};
		bool tr=true;
		for(j=M;j>=1;j--) {
			D[j]=D[j+1]-B[j]+C[j+1];
			if(D[j]<0) tr=false;
		}
		if(tr) {
			cnt=i;
		}
	}
	printf("%d",cnt);
}