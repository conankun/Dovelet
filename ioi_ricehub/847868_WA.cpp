#include<stdio.h>
#include<algorithm>
using namespace std;
long long R,L,B;
long long pos[1000000];
long long costs[1000000];
int main() {
	scanf("%lld%lld%lld",&R,&L,&B);
	int i,j;
	for(i=1;i<=R;i++) {
		scanf("%lld",&pos[i]);
	}
	int LP=1,RP=1;
	long long allcosts=0;
	long long mx=0;
	for(i=1;i<=R;i++) {
		if(i!=1) {
			if(RP < i) {
				LP=RP;
				RP=i;
			}
			//비용증가
			allcosts+=(i-LP)*(pos[i]-pos[i-1]);
			//비용감소!
			allcosts-=(RP-i)*(pos[i]-pos[i-1]);
		}
		while(allcosts>B && LP < i && RP > i) {
			if(LP == i || pos[RP]-pos[i] > pos[i]-pos[LP]) {
				allcosts-=pos[RP]-pos[i];
				RP--;
			} else if(RP == i || pos[i]-pos[LP] > pos[RP]-pos[i]) {
				allcosts-=pos[i]-pos[LP];
				LP++;
			} else break;
		}
		if(allcosts > B) continue;
		while(LP>1 || RP < R) {
			if(allcosts+pos[RP+1]-pos[i] <= B && (pos[RP+1]-pos[i] < pos[LP-1]-pos[i] || LP <= 1) && RP < R) {
				allcosts+=pos[RP+1]-pos[i];
				RP++;
			} else if(allcosts+pos[i]-pos[LP-1] <=B && (pos[i]-pos[LP-1] < pos[RP+1]-pos[i] || RP >=R ) && LP > 1) {
				allcosts+=pos[i]-pos[LP-1];
				LP--;
			} /**/else if(allcosts+pos[RP+1]-pos[i] <= B && (pos[RP+1]-pos[i] < pos[LP-1]-pos[i] || LP <= 1) && RP < R) {
				allcosts+=pos[RP+1]-pos[i];
				RP++;
			} else if(allcosts+pos[i]-pos[LP-1] <=B && (pos[i]-pos[LP-1] < pos[RP+1]-pos[i] || RP >=R ) && LP > 1) {
				allcosts+=pos[i]-pos[LP-1];
				LP--;
			} else break;
		}
		if(allcosts<=B && RP-LP+1 > mx){
			mx=RP-LP+1; 
		}
	}
	printf("%lld",mx);
}