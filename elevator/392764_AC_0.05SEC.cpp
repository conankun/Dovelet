#include<iostream>
#include<vector>
using namespace std;
int n,m;
int vis[1000];
int queue[1000000];
int front=1;
int back=1;
int now[1000000];
int backs[1000000];
int graph[1000][1000];
struct A {
	int x,y;
};
int s,e;
A data[10000];
int main() {
	cin>>n>>m;
	int i,j;
	for(i=1;i<=m;i++) cin>>data[i].x>>data[i].y;
	cin>>s>>e;
	for(i=1;i<=m;i++) {
		if((data[i].x == s || (s-data[i].x)%data[i].y == 0) && s >= data[i].x) {
			queue[back] = 1;
			vis[i] = 1;
			now[back++] = i;
		}
	}
	while(front < back) {
		for(i=data[now[front]].x;i<=n;i+=data[now[front]].y) {
			if(i == e) {
				cout<<queue[front]<<endl;
				int imsi[101]={0};
				int index=1;
				imsi[0] = now[front];
				int tr = backs[front];
				do {
					if(front == 1) break;
					imsi[index++] = now[tr];
					tr = backs[tr];
				}while(tr > 0);
				for(i=index-1;i>=0;i--) if(imsi[i] > 0) cout<<imsi[i]<<endl;
				return 0;
			}
			for(j=1;j<=m;j++) {
				if(vis[j] == 0 && (data[j].x == i || ( (i-data[j].x)%data[j].y == 0 && data[j].x+((i-data[j].x)/data[j].y)*data[j].y <= n )) && i >= data[j].x) {
					queue[back] = queue[front]+1;
					vis[j] = 1;
					now[back] = j;
					backs[back++] = front;
				}
			}
		}
		front++;
	}
	cout<<-1;
}