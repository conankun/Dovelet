#include<stdio.h>
#include<algorithm>
using namespace std;
int X,Y;
int bits[1000],inx;
int saves[100000],index;
void backtracking(int N,int level) {
	if(level==inx+1) {
		saves[++index]=N;
		return;
	} else {
		int xs=1,xsc=0;
		for(;xsc<=level-1;xs*=2,xsc++);
		xs/=2;xsc--;
		if(bits[level]==1) {
			backtracking(N+xs,level+1);
		}
		backtracking(N,level+1);
	}
}
int main() {
	scanf("%d",&Y);
	X=Y;
	while(X > 0) {
		bits[++inx]=X%2;
		X/=2;
	}
	backtracking(0,1);
	sort(saves+1,saves+1+index);
	for(int i=index;i>=1;i--) {
		if(saves[i]==0) continue;
		printf("%d\n",saves[i]);
	}
}