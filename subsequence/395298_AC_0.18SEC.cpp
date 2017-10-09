#include<iostream>
using namespace std;
int arr[200000];
int n,s;
int hap[200000];
int seq=0;
void search(int start,int low,int high) {
	int mid = (low+high)/2;
	if(low <= high) {
		if(hap[mid]-hap[start] >= s) {
			if(seq == 0 || mid-start < seq) {
				seq=mid-start;
			}
			search(start,low,mid-1);
		} else {
			search(start,mid+1,high);
		}
	}
}
int main() {
	scanf("%d%d",&n,&s);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&arr[i]);
	for(i=1;i<=n;i++) hap[i] = hap[i-1]+arr[i];
	for(i=1;i<=n;i++) {
		search(i-1,i,n);
	}
	printf("%d",seq);
}