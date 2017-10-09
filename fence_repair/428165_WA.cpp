#include<stdio.h>
#include<algorithm>
using namespace std;
int stick[100000];
int n;
int ans;
int sum;
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%d",&stick[i]);
		sum+=stick[i];
	}
	sort(stick+1,stick+1+n);
	for(i=n;i>=2;i--) {
		ans+=sum;
		sum-=stick[i];
	}
	printf("%d",ans);
}