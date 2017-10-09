#include<iostream>
#include<algorithm>
using namespace std;
int p[100000];
int n;
bool cmp(int a,int b) {
	return a > b;
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	sort(p+1,p+1+n,cmp);
	int sum=0;
	for(i=3;i<=n;i+=3) {
		sum+=p[i];
	}
	printf("%d",sum);
}