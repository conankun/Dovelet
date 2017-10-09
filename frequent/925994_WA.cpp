#include<stdio.h>
#include<iostream>
using namespace std;
int arr[222222];
int sum[222222];
int tree[3111111];
int n,q;
int go=0;
void binary_search(int low,int high,int target) { 
	int mid=(low+high)/2;
	if(low>high) return;
	if(arr[mid] <= target) {
		if(arr[mid]==target && go < mid) go=mid;
		binary_search(mid+1,high,target);
	} else if(arr[mid] > target) {
		binary_search(low,mid-1,target);
	}
}
int main() {
	scanf("%d%d",&n,&q);
	int i;
	int size=1;
	for(;size<=n;size*=2);
	for(i=1;i<=n;i++) {
		scanf("%d",&arr[i]);
		if(arr[i-1]!=arr[i]) sum[i]=1;
		else sum[i]=sum[i-1]+1;
		int rs=size+i;
		while(rs>0) {
			if(tree[rs] < sum[i]) {
				tree[rs]=sum[i];
			}
			rs/=2;
		}
	}
	for(i=1;i<=q;i++) {
		int p,q;
		scanf("%d%d",&p,&q);
		go=0;
		binary_search(p,q,arr[p]);
		int ls=size+go+1,rs=size+q,ok=1,mx=0;
		while(ls<=rs&&ok) {
			if(ls==rs) ok=0;
			if(ls%2==1) {
				if(tree[ls]> mx) mx=tree[ls];
				ls++;
			}
			if(rs%2==0) {
				if(tree[rs]>mx) mx=tree[rs];
				rs--;
			}
			ls/=2;
			rs/=2;
		}
		printf("%d\n",max(sum[go]-sum[p-1],mx));
	}
}