#include<iostream>
#include<algorithm>
using namespace std;
int n,c;
int barn[1000000];
int chk[1000000];
int mx=0;
void bsearch(int low,int high) {
	int mid = (low+high)/2;
	if(low<=high) {
		int i;
		int before=barn[1];
		int cnt=1;
		for(i=2;i<=n;i++) {
			if(barn[i]-before < mid) continue;
			else {
				cnt++;
				before=barn[i];
			}
			if(cnt >= c) break;
		}
		if(cnt >= c) {
			if(mid > mx) mx = mid;
			bsearch(mid+1,high);
		} else {
			bsearch(low,mid-1);
		}
	}
}
int main() {
	scanf("%d%d",&n,&c);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&barn[i]);
	sort(barn+1,barn+1+n);
	bsearch(barn[1],barn[n]);
	printf("%d",mx);
}