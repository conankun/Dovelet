#include<stdio.h>
#include<queue>
using namespace std;
queue<int> qu;
int visit[1000];
int graph[1000][1000];
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&graph[i][j]);
	qu.push(m);
	for(i=1;i<=n;i++) visit[i]=-1;
	visit[m]=0;
	while(!qu.empty()) {
		for(i=1;i<=n;i++) {
			if((visit[i] == -1&&graph[qu.front()][i]==1) || (visit[i] > visit[qu.front()]+graph[qu.front()][i] && graph[qu.front()][i] ==1)) {
				visit[i] = visit[qu.front()]+graph[qu.front()][i];
				qu.push(i);
			}
		}
		qu.pop();
	}
	int k;
	for(k=0;k<=n;k++) {
		for(i=1;i<=n;i++) {
			if(visit[i]==k) {
				printf("%d ",i);
			}
		}
		printf("\n");
	}
}