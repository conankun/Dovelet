#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
struct paper {
	int a,b;
	bool operator<(const paper &p) const {
		if(a==p.a) return b < p.b;
		return a < p.a;
	}
}P[1000];
int D[1000];
int main() {
	scanf("%d",&N);
	int i,j;
	for(i=1;i<=N;i++) {
		scanf("%d%d",&P[i].a,&P[i].b);
		if(P[i].a > P[i].b) {
			int temp=P[i].a;
			P[i].a=P[i].b;
			P[i].b=temp;
		}
	}
	sort(P+1,P+1+N);
	D[1]=1;
	int ans=1;
	for(i=2;i<=N;i++) {
		int mx=0;
		for(j=1;j<=i-1;j++){
			if(P[i].b >= P[j].b && D[j] > mx) mx = D[j];
		}
		D[i]=mx+1;
		if(D[i] > ans) ans = D[i];
	}
	printf("%d",ans);
}