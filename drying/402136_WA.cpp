#include<iostream>
#include<algorithm>
using namespace std;
int n;
int dry[1000000];
int dry2[1000000];
int k;
int mn=99999999;
void bsearch(int low,int high) {
	int mid = (low+high)/2;
	if(low<=high) {
		int i;
		for(i=1;i<=n;i++) {
			dry2[i]=dry[i];
			dry2[i]-=mid;
			if(dry2[i] < 0) dry2[i]=0;
		}
		int cnt=0;
		for(i=1;i<=n;i++) { 
			if(dry2[i]/k+(dry2[i]%k>0) >= 1) {
				dry2[i]++;
			}
			cnt+=dry2[i]/k+(dry2[i]%k>0);
		}
		if(cnt <= mid) {
			if(mn > mid) mn = mid;
			bsearch(low,mid-1);
		} else {
			bsearch(mid+1,high);
		}
	}
}
int main() {
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&dry[i]);
	scanf("%d",&k);
	sort(dry+1,dry+1+n);
	bsearch(1,dry[n]);
	printf("%d",mn);
}