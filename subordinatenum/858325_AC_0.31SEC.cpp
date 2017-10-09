#include<stdio.h>
#include<algorithm>
using namespace std;
long long X,Y;
long long bits[1000],inx;
long long saves[100000],index;
void backtracking(long long N,long long level) {
	if(level==inx+1) {
		saves[++index]=N;
		return;
	} else {
		long long xs=1,xsc=0;
		for(;xsc<=level-1;xs*=2,xsc++);
		xs/=2;xsc--;
		if(bits[level]==1) {
			backtracking(N+xs,level+1);
		}
		backtracking(N,level+1);
	}
}
int main() {
	scanf("%lld",&Y);
	X=Y;
	while(X > 0) {
		bits[++inx]=X%2;
		X/=2;
	}
	backtracking(0,1);
	sort(saves+1,saves+1+index);
	for(int i=index;i>=1;i--) {
		if(saves[i]==0) continue;
		printf("%lld\n",saves[i]);
	}
}