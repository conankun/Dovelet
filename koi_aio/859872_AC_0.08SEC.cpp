#include<stdio.h>
#include<algorithm>
using namespace std;
struct A {
	int a,b,c;
}arr[100000];
bool cmp(A a,A b) {
	return a.c > b.c;
}
int chk[1000];
int n;
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
	sort(arr+1,arr+1+n,cmp);
	int count=0;
	for(i=1;i<=n;i++) {
		if(chk[arr[i].a] < 2) {
			chk[arr[i].a]++;
			count++;
			printf("%d %d\n",arr[i].a,arr[i].b);
		}
		if(count == 3) break;
	}

}