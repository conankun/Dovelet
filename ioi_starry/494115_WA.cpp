#include<stdio.h>
#include<iostream>
using namespace std;
int H,W,vis[1000][1000],cnt,GP[1000][1000];
char map[1000][1000],numbering[1000];
struct INFO {
	int counts,miny,maxy,minx,maxx,x,y;
}info[501];
struct A {
	char map[111][111];
	int groupnum,x,y;
}group[501];
void dfs(int y,int x,int num) {
	info[num].counts++;
	if(info[num].miny > y || info[num].miny==0) info[num].miny=y;
	if(info[num].minx > x || info[num].minx==0) info[num].minx=x;
	if(info[num].maxy < y) info[num].maxy=y;
	if(info[num].maxx < x) info[num].maxx=x;
	vis[y][x]=1;
	GP[y][x]=num;
	if(vis[y+1][x]==0&&map[y+1][x]=='1') {
		dfs(y+1,x,num);
	}
	if(vis[y-1][x]==0&&map[y-1][x]=='1') {
		dfs(y-1,x,num);
	}
	if(vis[y][x+1]==0&&map[y][x+1]=='1') {
		dfs(y,x+1,num);
	}
	if(vis[y][x-1]==0&&map[y][x-1]=='1') {
		dfs(y,x-1,num);
	}
	//
	if(vis[y+1][x+1]==0&&map[y+1][x+1]=='1') {
		dfs(y+1,x+1,num);
	}
	if(vis[y+1][x-1]==0&&map[y+1][x-1]=='1') {
		dfs(y+1,x-1,num);
	}
	if(vis[y-1][x+1]==0&&map[y-1][x+1]=='1') {
		dfs(y-1,x+1,num);
	}
	if(vis[y-1][x-1]==0&&map[y-1][x-1]=='1') {
		dfs(y-1,x-1,num);
	}
}
A rotating(A a) { //90도
	A b={0};
	b.groupnum=a.groupnum;
	b.x=a.y;
	b.y=a.x;
	int i,j;
	for(i=1;i<=a.y;i++) {
		for(j=1;j<=a.x;j++) {
			b.map[j][a.y-i+1]=a.map[i][j];
		}
	}
	return b;
}
A lefts(A a) { //좌우뒤집음
	A b={0};
	b.x=a.x;
	b.y=a.y;
	b.groupnum=a.groupnum;
	int i,j;
	for(i=1;i<=a.y;i++) {
		for(j=1;j<=a.x;j++) {
			b.map[i][a.x-j+1]=a.map[i][j];	
		}
	}
	return b;	
}
A top(A a) { //상하 뒤집음
	A b={0};
	b.groupnum=a.groupnum;
	b.y=a.y;
	b.x=a.x;
	int i,j;
	for(i=1;i<=a.y;i++) {
		for(j=1;j<=a.x;j++) {
			b.map[a.y-i+1][j]=a.map[i][j];	
		}
	}
	return b;
}
bool isEqual(A a,A b) {
	int i,j;
	bool O=true;
	for(i=1;i<=max(a.y,b.y);i++) {
		for(j=1;j<=max(a.x,b.x);j++) {
			if(a.map[i][j] != b.map[i][j]) {
				O=false;
				break;
			}
		}
		if(!O) break;
	}
	return O;
}
int isSame(A a,A b) {
	//a 기준 b비교대상
	if(isEqual(a,b)) {
		return 1;
	}
	if(isEqual(a,lefts(b))) {
		return 1;
	}
	if(isEqual(a,top(b))) {
		return 1;
	}
	A n90=rotating(b);
	if(isEqual(a,n90)) return 1;
	if(isEqual(a,lefts(n90))) return 1;
	if(isEqual(a,top(n90))) return 1;
	A n180=rotating(n90);
	if(isEqual(a,n180)) return 1;
	if(isEqual(a,lefts(n180))) return 1;
	if(isEqual(a,top(n180))) return 1;
	A n270=rotating(n180);
	int i,j;
	/*for(i=1;i<=W;i++) {
		for(j=1;j<=H;j++) {
			if(n270.map[i][j]!=0) printf("%c",n270.map[i][j]);
			else printf("0");
		}
		printf("\n");
	}*/
	if(isEqual(a,n270)) return 1;
	if(isEqual(a,lefts(n270))) return 1;
	if(isEqual(a,top(n270))) return 1;
	return 0;
}
int main() {
	freopen("starry.in","r",stdin);
	freopen("starry.out","w",stdout);
	cin>>W>>H;
	int i,j,k;
	for(i=1;i<=H;i++) {
		for(j=1;j<=W;j++) {
			cin>>map[i][j];
		}
	}
	for(i=1;i<=H;i++) {
		for(j=1;j<=W;j++) {
			if(map[i][j]=='1'&&!vis[i][j]) {
				cnt++;
				dfs(i,j,cnt);
			}
		}
	}
	for(i=1;i<=cnt;i++) {
		int A=0,B=0;
		for(j=info[i].miny;j<=info[i].maxy;j++) {
			A++;
			B=0;
			for(k=info[i].minx;k<=info[i].maxx;k++) {
				B++;
				if(GP[j][k]!=i) {
					group[i].map[A][B]='0';
				} else {
					group[i].map[A][B]=map[j][k];
				}
			}
		}
		info[i].x=B;
		info[i].y=A;
		group[i].x=B;
		group[i].y=A;
		group[i].groupnum=i;
	}
	numbering[1]='a';
	char ac='a';
	for(i=2;i<=cnt;i++) {
		bool tas=false;
		for(j=1;j<=i-1;j++) {
			if(isSame(group[j],group[i])) {
				numbering[i]=numbering[j];
				tas=true;
				break;
			}
		}
		if(!tas) {
			ac++;
			numbering[i]=ac;
		}
	}
	for(i=1;i<=H;i++) {
		if(i>=2) printf("\n");
		for(j=1;j<=W;j++) {
			if(GP[i][j] != 0)printf("%c",numbering[GP[i][j]]);
			else printf("0");
		}
	}
}