#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int pos[10001];
int zim[10001];
int sortzim[1001];
int vis[1001];
int n,sum,mns=99999999;
void cycle(int s) {
	queue<int> qu;
	qu.push(s);
	int i;
	int hap=zim[s];
	int mn=zim[s];
	int size=0;
	vis[s]=1;
	while(!qu.empty()) {
		int f = qu.front();
		size++;
		if(vis[pos[zim[f]]] == 1) {
			vis[f]=1;
			if(zim[f] < mn) mn = zim[f];
			break;
		} else {
			hap+=zim[pos[zim[f]]];
			vis[f]=1;
			if(zim[f] < mn) mn = zim[f];
			qu.push(pos[zim[f]]);
		}
		qu.pop();
	}
	if(hap+(size-1)*mn < mn+hap+(size+1)*mns) {
		sum+=hap;
		sum+=(size-1)*mn;
	} else {
		sum+=mn+hap+(size+1)*mns;
	}
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%d",&zim[i]);
		sortzim[i]=zim[i];
		if(zim[i] < mns) mns = zim[i];
	}
	sort(sortzim+1,sortzim+1+n);
	for(i=1;i<=n;i++) pos[sortzim[i]]=i;
	for(i=1;i<=n;i++) {
		if(vis[i]==1)continue;
		if(sortzim[i] != zim[i]) cycle(i);
	}
	printf("%d",sum);
}