#include<iostream>
#include<algorithm>
using namespace std;
int n,s;
struct A {
	int h,c;
} cr[1000000];
bool cmp(A a , A b) {
	if(a.h < b.h) return 1;
	return 0;
}
int D[1000000];
int main() {
    scanf("%d%d",&n,&s);
    int i,j=1;
    for(i=1;i<=n;i++) {
		scanf("%d%d",&cr[i].h,&cr[i].c);
    }
	sort(cr+1,cr+1+n,cmp);
	int location=0,mx=0,mx2=0;
	for(i=1;i<=n;i++) {
		for(;j<i;j++) {
			if(cr[i].h-cr[j].h >= s && D[j]>=mx2) {
				location=j;
				mx2=D[j];
			} else if(cr[i].h-cr[j].h<s){
				j--;
				break;
			}
		}
		D[i] = D[location]+cr[i].c;
		if(D[i]> mx) mx = D[i];
	}
	printf("%d",mx);
}