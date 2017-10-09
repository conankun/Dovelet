#include<stdio.h>
int n;
char c[1000];
int main() {
	scanf("%d\n",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%c",&c[i]);
	int cnt=1;
	for(i=1;i<=n;i++) {
		if(c[i]=='S') {
			cnt++;
		} else {
			i++;
			cnt++;
		}
	}
	if(cnt> n) cnt=n;
	printf("%d",cnt);
}