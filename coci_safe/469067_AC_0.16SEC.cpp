#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long n;
long long pos[111111];
long long ans=-1;
int main() {
	scanf("%lld",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%lld",&pos[i]);
	sort(pos+1,pos+1+n);
	long long s1=0,s2=0,c1=0,c2=0;
	for(i=1;i<n/2+1;i++) {
		s1+=pos[i];
		c1++;
	}
	for(i=n/2+1+1;i<=n;i++) {
		s2+=pos[i];
		c2++;
	}
	int poss=1;
	for(i=n/2+1;i<=n;i++) {
		long long g = (c1*pos[i]-s1)+(s2-c2*pos[i]);
		if(ans == -1 || g < ans) ans = g;
		s1-=pos[poss];
		s2+=10000000+pos[poss];
		s1+=pos[i];
		s2-=pos[i+1];
		poss++;
	}
	s1=0,s2=0,c1=0,c2=0;
	for(i=1;i<n/2+1;i++) {
		s1+=pos[i];
		c1++;
	}
	for(i=n/2+1+1;i<=n;i++) {
		s2+=pos[i];
		c2++;
	}
	poss=n;
	for(i=n/2+1;i>=1;i--) {
		long long g = (c1*pos[i]-s1)+(s2-c2*pos[i]);
		if(ans == -1 || g < ans) ans = g;
		s1+=pos[poss]-10000000;
		s2-=pos[poss];
		s2+=pos[i];
		s1-=pos[i-1];
		poss--;
	}
	printf("%lld",ans);
	fclose(stdout);
	return 0;
}