#include<stdio.h>
#include<algorithm>
using namespace std;
int t,n,a[100];
struct A {
	int p;
	int t,c,s;
}b[10];
bool cmp(A aa,A bb) {
	if(aa.c==bb.c) return aa.s < bb.s;
	return aa.c > bb.c;
}
int main() {
	scanf("%d%d",&t,&n);
	int i;
	b[1].p=1;
	b[2].p=2;
	b[3].p=3;
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(b[3].t+a[i]<=t) {
			b[3].t+=a[i];
			b[3].c++;
			b[3].s+=b[3].t;
		}
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++) {
		if(b[1].t+a[i] <= t) {
			b[1].t+=a[i];b[1].c++;
			b[1].s+=b[1].t;
		}
		if(b[2].t+a[n-i+1] <= t) {
			b[2].t+=a[n-i+1];b[2].c++;
			b[2].s+=b[2].t;
		}
	}
	sort(b+1,b+4,cmp);
	if(b[1].c==b[2].c==b[3].c && b[1].s==b[2].s==b[3].s) {
		printf("Steve ");
	} else printf("%s ", b[1].p==1?"Steve":(b[1].p==2?"Linus":"Bill"));
	printf("wins with %d solved problems and a score of %d.",b[1].c,b[1].s);

}