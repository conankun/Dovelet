#include<stdio.h>
int D[4][4][4][4],D2[4][4][4][4],n,food[111111];
int score(int a,int b,int c) {
	int cnt=3;
	if(a==3 || (a==b || a==c)) cnt--;
	if(b==3 || (b==c)) cnt--;
	if(c==3) cnt--;
	return cnt;
}
int max(int a,int b) {
	if(a>b) return a;
	return b;
}
int main() {
	scanf("%d\n",&n);
	int i,j,a,b,c,d,e,f;
	for(i=1;i<=n;i++) {
		char c;
		scanf("%c",&c);
		if(c=='M') food[i]=0;
		else if(c=='B') food[i]=1;
		else if(c=='F') food[i]=2;
	}
	for(a=0;a<=3;a++) {
		for(b=0;b<=3;b++) {
			for(c=0;c<=3;c++) {
				for(d=0;d<=3;d++) {
						D[a][b][c][d]=-10000000;
						D2[a][b][c][d]=-10000000;
				}
			}
		}
	}
	D[3][3][3][3]=0;
	for(i=1;i<=n;i++) {
		for(a=0;a<=3;a++) {
			for(b=0;b<=3;b++) {
				for(c=0;c<=3;c++) {
					for(d=0;d<=3;d++) {
						if(a==3&&b==3&&c==3&&d==3) {
							a=a;
						}
						if(a==3) {
							D2[food[i]][3][c][d]=max(score(3,3,food[i])+D[a][b][c][d],D2[food[i]][3][c][d]);
						} else if(b==3) {
							D2[a][food[i]][c][d]=max(score(a,b,food[i])+D[a][b][c][d],D2[a][food[i]][c][d]);
						} else {
							D2[b][food[i]][c][d]=max(score(a,b,food[i])+D[a][b][c][d],D2[b][food[i]][c][d]);
						}
						if(c==3) {
							D2[a][b][food[i]][3]=max(score(3,3,food[i])+D[a][b][c][d],D2[a][b][food[i]][3]);
						} else if(d==3) {
							D2[a][b][c][food[i]]=max(score(3,c,food[i])+D[a][b][c][d],D2[a][b][c][food[i]]);
						} else {
							D2[a][b][d][food[i]]=max(score(c,d,food[i])+D[a][b][c][d],D2[a][b][d][food[i]]);
						}
					}
				}
			}
		}
		for(a=0;a<=3;a++) {
			for(b=0;b<=3;b++) {
				for(c=0;c<=3;c++) {
					for(d=0;d<=3;d++) {
						D[a][b][c][d]=D2[a][b][c][d];
						D2[a][b][c][d]=-10000000;
					}
				}
			}
		}
	}
	int ans=0;
	for(a=0;a<=3;a++) {
		for(b=0;b<=3;b++) {
			for(c=0;c<=3;c++) {
				for(d=0;d<=3;d++) {
					if(D[a][b][c][d] > ans) {
						ans = D[a][b][c][d];
					}
				}
			}
		}
	}
	printf("%d",ans);
}