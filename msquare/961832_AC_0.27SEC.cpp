#include<stdio.h>
#include<queue>
using namespace std;
int a,b,c,d,e,f,g,h;
struct A {
	int a,b,c,d,e,f,g,h;
	int dist;
};
queue<A> qu;
int vis[9][9][9][9][9][9][9][9];
int backt[9][9][9][9][9][9][9][9];
char backoutput[100000];
int idx;
queue<A> btqu;
int main() {
	scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
	A aa;
	aa.a=1,aa.b=2,aa.c=3,aa.d=4,aa.e=8,aa.f=7,aa.g=6,aa.h=5;
	aa.dist=1;
	vis[1][2][3][4][8][7][6][5]=1;
	qu.push(aa);
	while(!qu.empty()) {
		A quf = qu.front();
		qu.pop();
		if(quf.a == a && quf.b==b && quf.c == c && quf.d == d && quf.e == h && quf.f == g && quf.g == f && quf.h == e) {
			printf("%d\n",quf.dist-1);
			//backtrack
			btqu.push(quf);
			while(!btqu.empty()) {
				quf=btqu.front();
				btqu.pop();
				backoutput[++idx]=backt[quf.a][quf.b][quf.c][quf.d][quf.e][quf.f][quf.g][quf.h];
				if(backt[quf.a][quf.b][quf.c][quf.d][quf.e][quf.f][quf.g][quf.h]==1) {
					aa.a = quf.e;aa.b=quf.f;aa.c=quf.g;aa.d=quf.h;aa.e=quf.a;aa.f=quf.b;aa.g=quf.c;aa.h=quf.d;
					btqu.push(aa);
				} else if(backt[quf.a][quf.b][quf.c][quf.d][quf.e][quf.f][quf.g][quf.h]==2) {
					aa.a=quf.b;aa.b=quf.c;aa.c=quf.d;aa.d=quf.a;
					aa.e=quf.f;aa.f=quf.g;aa.g=quf.h;aa.h=quf.e;
					btqu.push(aa);
				} else if(backt[quf.a][quf.b][quf.c][quf.d][quf.e][quf.f][quf.g][quf.h]==3) {
					aa.a=quf.a;aa.e=quf.e;aa.d=quf.d;aa.h=quf.h;
					aa.c=quf.g;aa.b=quf.c;aa.f=quf.b;aa.g=quf.f;
					btqu.push(aa);
				}
			}
			int i;
			for(i=idx-1;i>=1;i--) printf("%c",'A'+backoutput[i]-1);
			return 0;
		}
		//A --> 1
		aa.a = quf.e;aa.b=quf.f;aa.c=quf.g;aa.d=quf.h;aa.e=quf.a;aa.f=quf.b;aa.g=quf.c;aa.h=quf.d;
		aa.dist=quf.dist+1;
		if(vis[aa.a][aa.b][aa.c][aa.d][aa.e][aa.f][aa.g][aa.h]!=1) {
			qu.push(aa);
			vis[aa.a][aa.b][aa.c][aa.d][aa.e][aa.f][aa.g][aa.h]=1;
			backt[aa.a][aa.b][aa.c][aa.d][aa.e][aa.f][aa.g][aa.h]=1;
		}
		//B --> 2
		aa.a=quf.d;aa.b=quf.a;aa.c=quf.b;aa.d=quf.c;
		aa.e=quf.h;aa.f=quf.e;aa.g=quf.f;aa.h=quf.g;
		aa.dist=quf.dist+1;
		if(vis[aa.a][aa.b][aa.c][aa.d][aa.e][aa.f][aa.g][aa.h]!=1) {
			qu.push(aa);
			vis[aa.a][aa.b][aa.c][aa.d][aa.e][aa.f][aa.g][aa.h]=1;
			backt[aa.a][aa.b][aa.c][aa.d][aa.e][aa.f][aa.g][aa.h]=2;
		}
		//C --> 3
		aa.a=quf.a;aa.e=quf.e;aa.d=quf.d;aa.h=quf.h;
		aa.c=quf.b;aa.b=quf.f;aa.f=quf.g;aa.g=quf.c;
		aa.dist=quf.dist+1;
		if(vis[aa.a][aa.b][aa.c][aa.d][aa.e][aa.f][aa.g][aa.h]!=1) {
			qu.push(aa);
			vis[aa.a][aa.b][aa.c][aa.d][aa.e][aa.f][aa.g][aa.h]=1;
			backt[aa.a][aa.b][aa.c][aa.d][aa.e][aa.f][aa.g][aa.h]=3;
		}
	}
}