#include<stdio.h>
int n,a[1000][3];
int main() {
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	}
	for(i=1;i<=n;i++) {
		int cnt=0;
		for(j=1;j<=n;j++) {
			if((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]) < (a[i][2]+a[j][2])*(a[i][2]+a[j][2])) {
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}
}