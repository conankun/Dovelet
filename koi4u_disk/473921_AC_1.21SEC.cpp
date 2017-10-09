#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
struct A {
	int ind,value,type;
	bool operator<(const A &a) const {
		return value < a.value;
	}
}tower[999999];
int key[999999];
int ans[999999];
int hi[999999];
int N,M;
int main() {
	scanf("%d%d",&N,&M);
	int i;
	for(i=1;i<=N;i++) {
		scanf("%d",&tower[i].value);
		tower[i].ind=i;
	}
	for(i=1;i<=M;i++) {
		scanf("%d",&tower[i+N].value);
		tower[i+N].ind=i;
		tower[i+N].type=1;
	}
	for(i=0;i<=N+M;i++) ans[i]=1100000000;
	std::sort(tower+1,tower+1+N+M);
	int ak=0;
	int h=2147483647;
	for(i=1;i<=N+M;i++) {
		if(tower[i].ind < h && tower[i].type==0) h = tower[i].ind;
		if(tower[i].value != tower[i-1].value) {
			ak++;
		}
		if(tower[i].type) {
			key[tower[i].ind]=ak;
		}
		ans[ak]=h;
	}
	int now=N+1;
	for(i=1;i<=M;i++) {
		if(now > ans[key[i]-1]-1) now = ans[key[i]-1]-1;
		else now--;
		if(now <= 0) {
			printf("0");
			return 0;
		}
	}
	printf("%d",now);
}