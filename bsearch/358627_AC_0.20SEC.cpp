#include<iostream>
using namespace std;
int data[1000000];
int vis[1000000];
int n;
int i;
int f;
bool isFind(int left,int right,int mid) {
	if(left>=right) return false;
	vis[mid]=1;
	if(data[mid] == f) {
		printf("%d",mid+1);
		return true;
	} else {
		if(data[mid] > f) {
			right = mid;
			mid = (left+right)/2;
			if(vis[mid] == 0)
			isFind(left,right,mid);
			else return false;
		} else if(data[mid] < f) {
			left = mid;
			mid = (left+right)/2;
			if(vis[mid] == 0)
			isFind(left,right,mid);
			else return false;
		} else return false;
	}
}
int main() {
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&data[i]);
	scanf("%d",&f);
	bool tr=isFind(0,n-1,n/2);
	if(!tr) {
		printf("not found");
	}
}