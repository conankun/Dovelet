#include<stdio.h>
int map[10][10];
int main() {
	int i,j;
	int mx=-1;
	int y=-1,x=-1;
	for(i=1;i<=9;i++) {
		for(j=1;j<=9;j++) {
			int n;
			scanf("%d",&n);
			if(mx < n) {
				y = i;
				x = j;
				mx = n;
			}
		}
	}
	printf("%d\n%d %d",mx,y,x);
}