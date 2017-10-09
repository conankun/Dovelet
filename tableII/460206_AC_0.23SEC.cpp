#include<stdio.h>
int table[5][5];
int sum[5];
int bt[10],vis[10];
int ans=-1;
void back(int level) {
	int i;
	if(level == 5) {
		int ss=0;
		for(i=1;i<=4;i++) {
			ss+=sum[i]-table[bt[i]][i];
		}
		if(ans == -1 || ans > ss) ans=ss;
	} else {
		for(i=1;i<=4;i++) {
			if(!vis[i]) {
				vis[i]=1;
				bt[level]=i;
				back(level+1);
				vis[i]=0;
			}
		}
	}
}
int main() {
	int i,j;
	for(i=1;i<=4;i++) {
		for(j=1;j<=4;j++) {
			scanf("%d",&table[i][j]);
			sum[j]+=table[i][j];
		}
	}
	back(1);
	printf("%d",ans);
}