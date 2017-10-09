#include<stdio.h>
#include<queue>
using namespace std;
int C[2000];
int A[30000];
int counts;
int M,N;
int main() {
	scanf("%d%d",&M,&N);
	int i,j;
	for(i=1;i<=N;i++) {
		scanf("%d",&A[i]);
		if(i>N/2) C[A[i]]++;//count++
	}
	int f=N/2;//finalpoint
	int cnt=0;
	for(i=1;i<=f;i++) {
		bool tr=false;
		for(j=A[i]+1;j<=M;j++) {
			if(C[j]>0) {
				C[j]--;
				cnt++;
				tr=true;
				break;
			}
		}

		//if not exist

		if(!tr) {
			for(j=f;j>i;j--) {
				if(A[j] > A[i]) {
					f=j-1;
					cnt++;
					tr=true;
					break;
				}
			}
		}

		if(!tr) break;
	}
	printf("%d",cnt);
}