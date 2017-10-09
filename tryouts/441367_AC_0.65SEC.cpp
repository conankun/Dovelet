#include<stdio.h>
#include<algorithm>
using namespace std;
long long n,A,B,C;
struct COW {
	long long h,w;
	long long value;
	bool operator<(const COW &a) const {
		return value < a.value;
	}
}cow[100011];
long long hs[100011];
long long hchk[100011];
long long hind;
long long ws[100011];
long long wchk[100011];
long long wind;
long long sum[100011];
long long chk[100011];
int main() {
	scanf("%lld%lld%lld%lld",&n,&A,&B,&C);
	long long i,j,k;
	for(i=1;i<=n;i++) {
		scanf("%lld%lld",&cow[i].h,&cow[i].w);
		cow[i].value = cow[i].h*A + cow[i].w*B - C;
		hs[i]=cow[i].h;
		ws[i]=cow[i].w;
	}
	sort(hs+1,hs+1+n);
	sort(ws+1,ws+1+n);
	sort(cow+1,cow+1+n);
	long long ans=0;
	for(i=1;i<=n;i++) {
		long long p=1;
		long long cnt=0,minus=0;
		for(j=1;j<=n;j++) {
			long long value = A*hs[i]+B*ws[j];
			for(k=p;k<=n;k++) {
				if(cow[k].value > value) {
					p = k;
					break;
				}
				if(cow[k].h >= hs[i]) {
					if(chk[cow[k].w] != i) {
						chk[cow[k].w]=i;
						sum[cow[k].w]=0;
					}
					sum[cow[k].w]++;
					cnt++;
					if(cow[k].w < ws[j]) {
						minus++;
						sum[cow[k].w]--;
					}
				}
				if(k==n) p = k+1;
			}
			for(k=ws[j-1];k<ws[j];k++) if(chk[k]==i) { minus+=sum[k]; sum[k]=0; }
			if(ans < cnt-minus) ans = cnt-minus;
		}
	}
	printf("%lld",ans);
}