#include<stdio.h>
int map[1000][1000];
int sum[1000];
int chk[1000];
int vis[1000];
int n;
int main() {
	int a,b;
	int i,j;
	while(scanf("%d%d",&a,&b) != -1) {
		if(a==0&&b==0)break;
		map[a][b]=1;
		sum[b]++;
		chk[a]=1;
		chk[b]=1;
	}
	int cnt=0,ind=-1;
	for(i=1;i<=1000;i++) {
		if(chk[i]==1) n++;
		if(sum[i] > 1) {
			printf("not a tree");
			return 0;
		}
		if(chk[i]==1&&sum[i]==0) {
			cnt++;
			ind=i;
		}
	}
	if(n==0) {
		printf("tree");
		return 0;
	}
	if(cnt!=1) {
		printf("not a tree");
		return 0;
	} else {
		while(n--) {
			int index=-1;
			for(j=1;j<=1000;j++) {
				if(vis[j]==0&&chk[j]==1&&sum[j]==0) {
					index=j;
					break;
				}
			}
			if(index == -1) {
				printf("not a tree");
				return 0;
			} else {
				vis[index]=1;
				for(j=1;j<=1000;j++) {
					if(map[index][j] == 1) {
						sum[j]--;
					}
				}
			}
		}
	}
	printf("tree");
}