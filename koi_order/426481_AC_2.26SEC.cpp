#include<stdio.h>
#include<algorithm>
using namespace std;
int tree[1000000];
int keys[1000000];
int S[1000000];
int dp[1000000];
int chk[1000000];
int n;
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&keys[i]);
	for(i=1;i<=n;i++) scanf("%d",&S[i]);
	sort(keys+1,keys+1+n);
	int size;
	for(size=1;size<n;size*=2);
	for(i=n;i>=1;i--) {
		int ls=size+1,rs=size+1+S[i];
		bool ok=true;
		int sums=0;
		int last=S[i]+1;
		int low=1,high=n;
		int ind=2147483647;
		while(low<=high) {
			int mid = (low+high)/2;
			ls=size+1,rs=size+mid;
			sums=0;
			ok=true;
			while(ls<=rs&&ok) {
				if(ls==rs) ok=false;
				if(ls%2==1) {
					sums+=tree[ls];
					ls++;
				}
				if(rs%2==0) {
					sums+=tree[rs];
					rs--;
				}
				ls/=2;
				rs/=2;
			}
			if(mid-sums >= S[i]+1) {
				if(chk[mid]==0) {
					if(mid < ind) ind = mid;
				}
				high = mid-1;
			} else {
				low = mid+1;
			}
		}
		dp[i]=ind;
		if(ind != 2147483647) chk[ind]=1;
		rs=size+ind;
		while(rs > 0) {
			tree[rs]+=1;
			rs/=2;
		}
	}
	for(i=1;i<=n;i++) printf("%d\n",keys[dp[i]]);
}