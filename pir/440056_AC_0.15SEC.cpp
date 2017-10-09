#include<stdio.h>
int arr[10000];
int a,b,mx=-2147483647;
int main() {
	int i,j;
	for(i=1;i<=20;i++) scanf("%d",&arr[i]);
	for(i=1;i<=20;i++) {
		for(j=i+1;j<=20;j++) {
			if(arr[i]+arr[j] > mx) {
				mx = arr[i]+arr[j];
				a = arr[i];
				b = arr[j];
			}
		}
	}
	printf("%d\n%d %d",mx,a,b);
}