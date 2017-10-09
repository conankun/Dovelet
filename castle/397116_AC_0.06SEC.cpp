#include<iostream>
#include<bitset>
using namespace std;
int m,n;
int map[52][52][52][52];
int cnt;//방의갯수.
int count;
int mx,mx2;//최대크기,깻을때 최대 크기.
int vis[100][100];
int flood[100000];
void DFS(int y,int x,int code) {
	vis[y][x]=code;
	if(y < 1 || x < 1 || y > n || x > m) return;
	else {
		count++;
		if(map[y][x][y-1][x] == 1 && vis[y-1][x] == 0) {
			DFS(y-1,x,code);
		}
		if(map[y][x][y+1][x] == 1 && vis[y+1][x] == 0) {
			DFS(y+1,x,code);
		}
		if(map[y][x][y][x+1] == 1 && vis[y][x+1] == 0) {
			DFS(y,x+1,code);
		}
		if(map[y][x][y][x-1] == 1 && vis[y][x-1] == 0) {
			DFS(y,x-1,code);
		}
	}
}
int main() {
	cin>>m>>n;
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			int a;
			cin>>a;
			bitset<32> bits(a);
			if(bits[0] == 1) {
				map[i][j][i][j-1] = -1;
				map[i][j-1][i][j] = -1;
			} else {
				map[i][j][i][j-1] = 1;
				map[i][j-1][i][j] = 1;
			}
			if(bits[1] == 1) {
				map[i][j][i-1][j] = -1;
				map[i-1][j][i][j] = -1;
			} else {
				map[i][j][i-1][j]=1;
				map[i-1][j][i][j]=1;
			}
			if(bits[2] == 1) {
				map[i][j][i][j+1]=-1;
				map[i][j+1][i][j]=-1;
			} else {
				map[i][j][i][j+1]=1;
				map[i][j][i][j+1]=1;
			}
			if(bits[3] == 1) {
				map[i][j][i+1][j]=-1;
				map[i+1][j][i][j]=-1;
			} else {
				map[i][j][i+1][j]=1;
				map[i+1][j][i][j]=1;
			}
		}
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if(vis[i][j] == 0) {
				cnt++;
				count=0;
				DFS(i,j,cnt);
				if(count > mx) mx = count;
				flood[cnt]=count;
			}
		}
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if(vis[i][j] != vis[i+1][j] && map[i][j][i+1][j] == -1) {
				if(flood[vis[i][j]]+flood[vis[i+1][j]] > mx2) mx2 = flood[vis[i][j]]+flood[vis[i+1][j]];
			}
			if(vis[i][j] != vis[i-1][j] && map[i][j][i-1][j] == -1) {
				if(flood[vis[i][j]]+flood[vis[i-1][j]] > mx2) mx2 = flood[vis[i][j]]+flood[vis[i-1][j]];
			}
			if(vis[i][j] != vis[i][j+1] && map[i][j][i][j+1] == -1) {
				if(flood[vis[i][j]]+flood[vis[i][j+1]] > mx2) mx2 = flood[vis[i][j]]+flood[vis[i][j+1]];
			}
			if(vis[i][j] != vis[i][j-1] && map[i][j][i][j-1] == -1) {
				if(flood[vis[i][j]]+flood[vis[i][j-1]] > mx2) mx2 = flood[vis[i][j]]+flood[vis[i][j-1]];
			}
		}
	}
	cout<<cnt<<endl<<mx<<endl<<mx2;
}