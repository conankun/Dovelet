#include<stdio.h>
int D[4][4][4][4][4][4],D2[4][4][4][4][4][4],n,food[111111];
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
					for(e=0;e<=3;e++) {
						for(f=0;f<=3;f++) {
							D[a][b][c][d][e][f]=-10000000;
							D2[a][b][c][d][e][f]=-10000000;
						}
					}
				}
			}
		}
	}
	D[3][3][3][3][3][3]=0;
	for(i=1;i<=n;i++) {
		for(a=0;a<=3;a++) {
			int g=(a==3?0:0);
			for(b=g;b<=3;b++) {
				int g2=(b==3?0:0);
				for(c=g2;c<=3;c++) {
					for(d=0;d<=3;d++) {
						int g3=(d==3?0:0);
						for(e=g3;e<=3;e++) {
							int g4=(e==3?0:0);
							for(f=g4;f<=3;f++) {
								//D[a][b][c][d][e][f]
								/*
									D2[b][c][food[i]][d][e][f] 또는
									D2[a][b][c][e][f][food[i]] 가 됨.
								*/
								D2[b][c][food[i]][d][e][f]=max(score(b,c,food[i])+D[a][b][c][d][e][f],D2[b][c][food[i]][d][e][f]);
								D2[a][b][c][e][f][food[i]]=max(score(e,f,food[i])+D[a][b][c][d][e][f],D2[a][b][c][e][f][food[i]]);
							}
						}
					}
				}
			}
		}
		for(a=0;a<=3;a++) {
			for(b=0;b<=3;b++) {
				for(c=0;c<=3;c++) {
					for(d=0;d<=3;d++) {
						for(e=0;e<=3;e++) {
							for(f=0;f<=3;f++) {
								D[a][b][c][d][e][f]=D2[a][b][c][d][e][f];
								D2[a][b][c][d][e][f]=-10000000;
							}
						}
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
					for(e=0;e<=3;e++) {
						for(f=0;f<=3;f++) {
							if(D[a][b][c][d][e][f] > ans) {
								ans = D[a][b][c][d][e][f];
							}
						}
					}
				}
			}
		}
	}
	printf("%d",ans);
}