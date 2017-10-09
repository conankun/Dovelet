#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
struct A {
	int h,m,s;
}arr[100000];
bool cmp(A a,A b) {
	int c = a.h*3600+a.m*60+a.s;
	int d = b.h*3600+b.m*60+b.s;
	return c<d;
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d%d%d",&arr[i].h,&arr[i].m,&arr[i].s);
	sort(arr+1,arr+1+n,cmp);
	for(i=1;i<=n;i++) printf("%d %d %d\n",arr[i].h,arr[i].m,arr[i].s);
}