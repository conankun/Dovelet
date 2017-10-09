#include<stdio.h>
#include<math.h>
int g[100][11]; //pow(10,i)+g[i-1]*9;
int main() {
	int n;
	int i,j;
	for(i=5;i<=9;i++)  g[1][i]=1;
	int sums=1;
	for(i=2;i<=11;i++) {
		for(j=1;j<=9;j++) {
			if(j==4) continue;
			if(j == 5) {
				g[i][j]+=pow(10,i-1);
				g[i][j]+=g[i][j-2]+sums;
			}  else {
				g[i][j]+=g[i][j-1]+sums;
			}
		}
		sums+=g[i][9];
	}
	scanf("%d",&n);
	int m=n;
	int c=1;
	int sum=0;
	while(m > 0) {
		sum+=g[c][m%10];
		m/=10;
		c++;
	}
	printf("%d: %d\n",n,n-sum);
}