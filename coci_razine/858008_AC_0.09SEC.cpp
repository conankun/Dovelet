#include<stdio.h>
#include<stdlib.h>
int n;
int arr[1000];
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&arr[i]);
	long long sum=0;
	for(i=n;i>=1;i--) {
		if(arr[i] <= arr[i-1]) {
			sum+=abs(arr[i-1]-(arr[i]-1));
			arr[i-1]=arr[i]-1;
		}
	}
	printf("%d",sum);
}