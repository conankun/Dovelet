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
int main() {
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
		A b=group[i];
		A left360 = lefts(b);
		A top360 = top(b);
		//
		A n90=rotating(b);
		A leftn90=lefts(n90);
		A topn90=top(n90);
		//
		A n180=rotating(n90);
		A leftn180=lefts(n180);
		A topn180=top(n180);
		//
		A n270=rotating(n180);
		A leftn270=lefts(n270);
		A topn270=top(n270);
		for(j=1;j<=i-1;j++) {
			if(isEqual(group[j],b)) tas=true;
			else if(isEqual(group[j],left360)) tas=true;
			else if(isEqual(group[j],top360)) tas=true;
			else if(isEqual(group[j],n90)) tas=true;
			else if(isEqual(group[j],leftn90)) tas=true;
			else if(isEqual(group[j],topn90)) tas=true;
			else if(isEqual(group[j],n180)) tas=true;
			else if(isEqual(group[j],leftn180)) tas=true;
			else if(isEqual(group[j],topn180)) tas=true;
			else if(isEqual(group[j],n270)) tas=true;
			else if(isEqual(group[j],leftn270)) tas=true;
			else if(isEqual(group[j],topn270)) tas=true;
			if(tas) {
				numbering[i]=numbering[j];
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