#include<stdio.h>
#include<algorithm>
int arr[10000];
int all[10000];
int ind;
int n;
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&arr[i]);
	for(i=1;i<=n-1;i++) {
		all[++ind]=arr[i+1]-arr[i];
	}
	std::stable_sort(all+1,all+1+ind);
	int cnt=1;
	for(i=2;i<=ind;i++) {
		if(all[i] != all[i-1]) cnt++;
	}
	printf("%d",cnt);
}