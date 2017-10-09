#include<stdio.h>
#include<algorithm>
char s[10000000];
int n;
int ans=1;
int y[10000000];
int ind;
int main() {
	scanf("%s",&s[1]);
	int i,j,k;
	for(i=1;;i++) {
		if(s[i]) n++;
		else break;
	}
	for(i=1;i*i<=n;i++) {
		if(n%i==0) {
			y[++ind]=i;
			if(i!=n/i) y[++ind]=n/i;
		}
	}
	std::sort(y+1,y+1+ind);
	for(i=1;i<=ind;i++) {
		bool t=true;
		int cnt=1;
		for(j=y[i]+1;j<=n;j+=y[i]) {
			for(k=j;k<=j+y[i]-1;k++) {
				if(s[k] != s[k-y[i]]) {
					t=false;
					break;
				}
			}
			if(t) cnt++;
			else break;
		}
		if(t) {
			ans=cnt;
			break;
		}
	}
	printf("%d",ans);
}