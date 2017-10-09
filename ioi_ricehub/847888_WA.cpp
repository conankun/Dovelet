#include<stdio.h>
#include<algorithm>
using namespace std;
long long R,L,B;
long long pos[1000000];
long long costs[1000000];
long long mx=1;
void bs(long long low,long long high) {
	long long mid=(low+high)/2;//length
	if(mid<=2 || mid>R || low>high) return;
	long long i,j;
	long long leftsum=0,rightsum=0,rightsum2,leftsum2;
	bool poss=false;
	for(i=1;i<=mid/2+1;i++) {
		leftsum+=pos[i];
	}
	leftsum2=pos[mid/2+1]*(mid/2+1)-leftsum;
	for(i=mid/2+2;i<=mid;i++) {
		rightsum+=pos[i];
	}
	rightsum2=rightsum-(pos[mid/2+1]*(mid-(mid/2+1)));
	if(leftsum2+rightsum2<=B) poss=true;
	long long cnts=1;
	long long b4=mid/2+1;
	for(i=mid+1;i<=R;i++) {
		leftsum-=pos[cnts];
		leftsum+=pos[b4+1];
		cnts++;
		b4++;
		rightsum+=pos[i];
		rightsum-=pos[b4];
		leftsum2=pos[b4]*(mid/2+1)-leftsum;
		rightsum2=rightsum-(pos[b4]*(mid-(mid/2+1)));
		if(leftsum2+rightsum2<=B) poss=true;
	}
	if(poss) {
		if(mx < mid) mx=mid;
		bs(mid+1,high);
	} else {
		bs(low,mid-1);
	}
}
int main() {
	freopen("input.txt","r",stdin);
	scanf("%lld%lld%lld",&R,&L,&B);
	int i,j;
	for(i=1;i<=R;i++) {
		scanf("%lld",&pos[i]);
	}
	for(i=2;i<=R;i++) {
		if(pos[i]-pos[i-1] <= B) mx=2;
	}
	bs(1,R);
	printf("%lld",mx);
}