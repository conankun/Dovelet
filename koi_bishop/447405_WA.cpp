#include<stdio.h>
#include<algorithm>
int n;
int m;
int map[201][201];
int num1[201][201];
int num2[201][201];
int pos[5001][5001]; // i->j 가 어디에 있는지.
int start[5001];
int end[5001];
struct G {
	int s,e,v;
	bool operator<(const G &a) const {
		if(a.s == s) return e < a.e;
		return s < a.s;
	}
}Graph[20011];
int size;
int vertex1,vertex2;
int vis[10011];
int back[10011];
int ind;
int flow;
bool dfs(int node) {
	if(node == vertex1+vertex2+1) {
		int i;
		flow++;
		for(i=1;i<=ind;i++) {
			Graph[back[i]].v=0;
			Graph[pos[Graph[back[i]].e][Graph[back[i]].s]].v=1;
		}
		return true;
	} else {
		int i;
		for(i=start[node];i<=end[node];i++) {
			if(!vis[Graph[i].e] && Graph[i].v > 0) {
				vis[Graph[i].e]=1;
				back[++ind]=i;
				bool g = dfs(Graph[i].e);
				ind--;
				if(g) return true;
			}
		}
	}
	return false;
}
void nf() {
	int i;
	vis[0]=1;
	while(dfs(0)) {
		for(i=0;i<=vertex1+vertex2+1;i++) vis[i]=0;
		vis[0]=1;
		ind=0;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		map[a][b]=-1;
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(map[i][j] == -1) continue;
			else {
				if(num1[i-1][j-1] != 0) 	{
					num1[i][j] = num1[i-1][j-1];
				} else {
					num1[i][j] = ++vertex1;
				}
			}
		}
	}
	for(i=1;i<=n;i++) {
		for(j=n;j>=1;j--) {
			if(map[i][j] == -1) continue;
			else {
				if(num2[i-1][j+1] != 0) 	{
					num2[i][j] = num2[i-1][j+1];
				} else {
					num2[i][j] = ++vertex2;
				}
			}
		}
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(map[i][j] == -1) continue;
			G g;
			g.s = num1[i][j];
			g.e = vertex1+num2[i][j];
			g.v = 1;
			Graph[++size]=g;
			g.e = num1[i][j];
			g.s = vertex1+num2[i][j];
			g.v = 0;
			Graph[++size]=g;
		}
	}
	for(i=1;i<=vertex1;i++) {
		G g;
		g.s = 0;
		g.e = i;
		g.v = 1;
		Graph[++size]=g;
		g.e = 0;
		g.s = i;
		g.v = 0;
		Graph[++size]=g;
	}
	for(i=1;i<=vertex2;i++) {
		G g;
		g.s = vertex1+i;
		g.e = vertex1+vertex2+1;
		g.v = 1;
		Graph[++size]=g;
		g.e = g.s;
		g.s = vertex1+vertex2+1;
		g.v=0;
		Graph[++size]=g;
	}
	std::sort(Graph+1,Graph+1+size);
	start[Graph[1].s]=1;
	if(Graph[1].s != Graph[2].s) {
		end[Graph[1].s]=1;
		start[Graph[2].s]=2;
	}
	pos[Graph[1].s][Graph[1].e]=1;
	for(i=2;i<=size;i++) {
		if(Graph[i].s != Graph[i+1].s) {
			end[Graph[i].s]=i;
			if(i+1 <= size) start[Graph[i+1].s]=i+1;
		}
		pos[Graph[i].s][Graph[i].e]=i;
	}
	nf();
	printf("%d",flow);
}