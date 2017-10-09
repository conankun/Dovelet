#include<stdio.h>
int n,sum,p[10];
int main() {
	scanf("%d",&n);
	int m=n;
	while(m>0) {
		sum++;
		p[m%10]++;
		m/=10;
	}
	int s=0,pp[10];
	int i,j;
	int ans=0;
	for(i=n+1;;i++) {
		for(j=0;j<=9;j++) pp[j]=0;
		m=i;
		s=0;
		while(m>0) {
			s++;
			pp[m%10]++;
			m/=10;
		}
		bool t=true;
		for(j=0;j<=9;j++) {
			if(pp[j]!=p[j]) {
				t=false;
				break;
			}
		}
		if(t) ans = i;
		if(ans) break;
		if(s > sum) break;
	}
	printf("%d",ans);
}