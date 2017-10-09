#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int stick[100000];
int n;
int ans;
int sum;
int hap[100000];
void divcon(int s,int e) {
	if(e-s < 1) return;
	ans += hap[e]-hap[s-1];
	if(e-s <= 1) return;
	divcon(s,(s+e)/2);
	divcon((s+e)/2+1,e);
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%d",&stick[i]);
		sum+=stick[i];
		hap[i] = hap[i-1]+stick[i];
	}
	sort(stick+1,stick+1+n);
	divcon(1,n);
	printf("%d",ans);
}