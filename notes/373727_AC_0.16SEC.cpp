#include<iostream>
using namespace std;
struct A {
	int a,b;
};
int n,q;
int bit[100000];
A g[100000];
int bs(int low,int high,int find) {
	int mid=low+high;
	mid/=2;
	if(low<=high) {
		if(g[mid].a <= find && g[mid].b > find) {
			return mid;
		} else {
			if(g[mid].a > find) {
				return bs(low,mid-1,find);
			} else {
				return bs(mid+1,high,find);
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d%d",&n,&q);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&bit[i]);
	for(i=1;i<=n;i++) {
		g[i].a = g[i-1].b;
		g[i].b = g[i-1].b+bit[i];
	}
	for(i=1;i<=q;i++) {
		int c;
		scanf("%d",&c);
		printf("%d\n",bs(1,n,c));
	}
}