#include<stdio.h>
#include<vector>
using namespace std;
int M,N;
int map[101][101];
int vis[101][101];
int chk[11111];
int group[101][101];
vector<int> ve[11111];
int cnt;
struct A {
	int ind,dis;
};
A qu[100001];
A qus[100001];
int h=1,t;
vector<int> dischk[10001];
int quvis[100001];
int v[100001];
int isIn[100001];
void dfs(int y,int x,int mode) {
	vis[y][x]=1;
	if(!mode) group[y][x]=cnt;
	if(vis[y+1][x]==0&&map[y+1][x]==map[y][x]&&y+1<=M) {
		dfs(y+1,x,mode);
	} else if(y+1<=M&&map[y+1][x]!=map[y][x]&&mode) {
		if(chk[group[y+1][x]]!=group[y][x]) {
			chk[group[y+1][x]]=group[y][x];
			ve[group[y][x]].push_back(group[y+1][x]);
		}
	} if(vis[y-1][x]==0&&map[y-1][x]==map[y][x]&&y-1>=1) {
		dfs(y-1,x,mode);
	} else if(y-1>=1&&map[y-1][x]!=map[y][x]&&mode) {
		if(chk[group[y-1][x]]!=group[y][x]) {
			chk[group[y-1][x]]=group[y][x];
			ve[group[y][x]].push_back(group[y-1][x]);
		}
	}if(vis[y][x+1]==0&&map[y][x+1]==map[y][x]&&x+1<=N) {
		dfs(y,x+1,mode);
	} else if(x+1<=N&&map[y][x+1]!=map[y][x]&&mode) {
		if(chk[group[y][x+1]]!=group[y][x]) {
			chk[group[y][x+1]]=group[y][x];
			ve[group[y][x]].push_back(group[y][x+1]);
		}
	} if(vis[y][x-1]==0&&map[y][x-1]==map[y][x]&&x-1>=1) {
		dfs(y,x-1,mode);
	} else if(x-1>=1&&map[y][x-1]!=map[y][x]&&mode) {
		if(chk[group[y][x-1]]!=group[y][x]) {
			chk[group[y][x-1]]=group[y][x];
			ve[group[y][x]].push_back(group[y][x-1]);
		}
	}
}
int main() {
	freopen("INPUT.TXT","r",stdin);
	freopen("OUTPUT.TXT","w",stdout);
	scanf("%d%d",&M,&N);
	int i,j;
	for(i=1;i<=M;i++) {
		for(j=1;j<=N;j++) {
			scanf("%d",&map[i][j]);
		}
	}
	for(i=1;i<=M;i++) {
		for(j=1;j<=N;j++) {
			if(!vis[i][j]) {
				cnt++;
				dfs(i,j,0);
			}
		}
	}
	for(i=1;i<=M;i++) for(j=1;j<=N;j++) vis[i][j]=0;
	for(i=1;i<=M;i++) {
		for(j=1;j<=N;j++) {
			if(!vis[i][j]) {
				dfs(i,j,1);
			}
		}
	}
	qu[++t].ind=1;
	qu[t].dis=0;
	quvis[1]=1;
	int mx=0;
	dischk[0].push_back(1);
	while(h<=t) {
		for(i=0;i<ve[qu[h].ind].size();i++) {
			if(!quvis[ve[qu[h].ind][i]]) {
				quvis[ve[qu[h].ind][i]]=1;
				qu[++t].ind=ve[qu[h].ind][i];
				qu[t].dis = qu[h].dis+1;
				dischk[qu[h].dis+1].push_back(ve[qu[h].ind][i]);
				if(mx < qu[t].dis) {
					mx=qu[t].dis;
				}
			}
		}
		h++;
	}
	if(mx==M+N-2) {//체스판인경우;;
		printf("%d",min((M%2==1?M-1:M),(N%2==1?N-1:N)));
		return 0;
	}
	int l=mx/2;
	h=1,t=0;
	for(l=1;l<=mx/2+5;l++)
	for(i=0;i<dischk[l].size();i++) {
		qu[++t].ind = dischk[l][i];
		isIn[dischk[l][i]]=1;
	}
	int cnts=0;
	int ans=0;
	while(h<=t) {
		cnts++;
		v[qu[h].ind]=cnts;
		int hh=1,tt=0;
		qus[++tt].ind = qu[h].ind;
		qus[tt].dis = 0;
		int lo=0;
		while(hh<=tt) {
			for(i=0;i<ve[qus[hh].ind].size();i++) {
				if(v[ve[qus[hh].ind][i]]!=cnts) {
					v[ve[qus[hh].ind][i]]=cnts;
					qus[++tt].ind = ve[qus[hh].ind][i];
					qus[tt].dis = qus[hh].dis+1;
					if(qus[tt].dis > lo) lo = qus[tt].dis;
				}
			}
			hh++;
		}
		if(lo < ans || ans == 0) {
			ans = lo;
			for(i=0;i<ve[qu[h].ind].size();i++) {
				if(!isIn[ve[qu[h].ind][i]]) {
					isIn[ve[qu[h].ind][i]]=1;
					qu[++t].ind = ve[qu[h].ind][i];
				}
			}
		}
		h++;
	}
	printf("%d",ans);
	fclose(stdout);
	fclose(stdin);
	return 0;
}