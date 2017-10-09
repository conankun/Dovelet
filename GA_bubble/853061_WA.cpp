#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int N;
int arr[1000000];
int pos[1000000];
int main() {
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++) scanf("%d",&arr[i]);
	for(i=1;i<=N;i++) {
		pos[arr[i]]=i;
	}
	long long cnt=0;
	for(i=1;i<=N;i++) {
		cnt+=abs(pos[i]-i);
	}
	printf("%lld",cnt/2);
}