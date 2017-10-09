#include<iostream>
using namespace std;
int rect[100][100];
int a[100][100]; //세로
int b[100][100]; //가로
int cnt;
struct A {
	int x,y;
};
int map[100][100];
A pos[1000];
bool t=false;
void back(int level) {
	int i = pos[level+1].y;
	int j = pos[level+1].x;
	if(level == cnt) {
		for(i=1;i<=9;i++) {
			for(j=1;j<=9;j++) {
				cout<<map[i][j];
			}
			cout<<endl;
		}
		t=true;
		return;
	} else {
		int g;
		if(i >= 1 && i <= 3 && j >= 1 && j <= 3) {
			g=1;
		} else if(i >= 1 && i <= 3 && j >= 4 && j <= 6) {
			g=2;
		} else if(i >= 1 && i <= 3 && j >= 7 && j<= 9) {
			g=3;
		} else if(i >= 4 && i<= 6 && j >= 1 && j <= 3) {
			g=4;
		} else if(i >= 4 && i <= 6 && j >= 4 && j <=6) {
			g=5;
		} else if(i >= 4 && i <= 6 && j >= 7 && j <= 9) {
			g=6;
		} else if(i >= 7 && i <= 9 && j >= 1 && j <= 3) {
			g=7;
		} else if(i >= 7 && i <= 9 && j >= 4 && j <= 6) {
			g=8;
		} else if(i >= 7 && i <= 9 && j >= 7 && j <= 9) {
			g=9;
		}
		int k;
		for(k=1;k<=9;k++) {
			if(rect[g][k] == 0 && a[i][k] == 0 && b[j][k] == 0 && !t) {
				map[i][j] = k;
				rect[g][k] = 1;
				a[i][k]=1;
				b[j][k]=1;
				back(level+1);
				map[i][j] = 0;
				rect[g][k] = 0;
				a[i][k]=0;
				b[j][k]=0;
			}
		}
	}
}
int main() {
	int i,j;
	char c;
	int n;
	for(i=1;i<=9;i++) {
		for(j=1;j<=9;j++) {
			cin>>c;
			n=c-'0';
			map[i][j]=n;
			if(n == 0) {
				A c;
				c.x = j;
				c.y = i;
				pos[++cnt]=c;
			} else {
				int g;
				if(i >= 1 && i <= 3 && j >= 1 && j <= 3) {
					g=1;
				} else if(i >= 1 && i <= 3 && j >= 4 && j <= 6) {
					g=2;
				} else if(i >= 1 && i <= 3 && j >= 7 && j<= 9) {
					g=3;
				} else if(i >= 4 && i<= 6 && j >= 1 && j <= 3) {
					g=4;
				} else if(i >= 4 && i <= 6 && j >= 4 && j <=6) {
					g=5;
				} else if(i >= 4 && i <= 6 && j >= 7 && j <= 9) {
					g=6;
				} else if(i >= 7 && i <= 9 && j >= 1 && j <= 3) {
					g=7;
				} else if(i >= 7 && i <= 9 && j >= 4 && j <= 6) {
					g=8;
				} else if(i >= 7 && i <= 9 && j >= 7 && j <= 9) {
					g=9;
				}
				rect[g][n]=1;
				b[j][n]=1;
				a[i][n]=1;
			}
		}
	}
	back(0);
}