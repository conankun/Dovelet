#include<stdio.h>
int n,m;
int budge[11111];
int mx=0,l=0;
void search(int low,int high) {
	int mid = (low+high)/2;
	if(low>high) return;
	int i,sum=0;
	for(i=1;i<=n;i++) {
		if(budge[i] > mid) sum+=mid;
		else sum+=budge[i];
	}
	if(sum > m) {
		search(low,mid-1);
	} else {
		if(sum > mx) {
			mx = sum;
			l=mid;
		}
		search(mid+1,high);
	}
}
int main() {
	scanf("%d",&n);
	int i,j=0;
	for(i=1;i<=n;i++) {
		scanf("%d",&budge[i]);
		if(budge[i] > j) j = budge[i];
	}
	scanf("%d",&m);
	search(1,j);
	printf("%d",l);
}