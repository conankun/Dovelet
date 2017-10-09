#include<stdio.h>
#include<algorithm>
using namespace std;
int n,A,B,C;
struct COW {
	int h,w;
	int value;
	bool operator<(const COW &a) const {
		return value < a.value;
	}
}cow[100011];
int hs[100011];
int hchk[100011];
int hind;
int ws[100011];
int wchk[100011];
int wind;
int sum[100011];
int chk[100011];
int main() {
	scanf("%d%d%d%d",&n,&A,&B,&C);
	int i,j,k;
	for(i=1;i<=n;i++) {
		scanf("%d%d",&cow[i].h,&cow[i].w);
		cow[i].value = cow[i].h*A + cow[i].w*B - C;
		hs[i]=cow[i].h;
		ws[i]=cow[i].w;
	}
	sort(hs+1,hs+1+n);
	sort(ws+1,ws+1+n);
	sort(cow+1,cow+1+n);
	int ans=0;
	for(i=1;i<=n;i++) {
		int p=1;
		int cnt=0,minus=0;
		for(j=1;j<=n;j++) {
			int value = A*hs[i]+B*ws[j];
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
	printf("%d",ans);
}