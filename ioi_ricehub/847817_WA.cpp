#include<stdio.h>
#include<algorithm>
using namespace std;
long long R,L,B;
long long pos[1000000];
long long costs[1000000];
int main() {
	scanf("%lld%lld%lld",&R,&L,&B);
	long long mid=R/2+1;
	int i;
	for(i=1;i<=R;i++) {
		scanf("%lld",&pos[i]);
	}
	for(i=1;i<=R;i++) {
		costs[i] = abs(pos[i]-pos[mid]);
	}
	sort(costs+1,costs+1+R);
	long long ps=0,cnt=0;
	for(i=1;i<=R;i++) {
		if(ps+costs[i] <= B) {
			cnt++;
			ps+=costs[i];
		}
	}
	printf("%lld",cnt);
}