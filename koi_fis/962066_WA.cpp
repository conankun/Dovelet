#include<stdio.h>
int N,d,k,c;
int data[3333333];
int vis[3333333];
int main() {
	scanf("%d%d%d%d",&N,&d,&k,&c);
	int i;
	for(i=1;i<=N;i++) scanf("%d",&data[i]);
	int va=0;
	for(i=1;i<=k;i++) {
		if(vis[data[i]]==0) va++;
		vis[data[i]]++;
		data[N+k]=data[i];
	}
	int mx=0;
	for(i=2;i<=N;i++) {
		if(vis[data[i-1]]==1) va--;
		vis[data[i-1]]--;
		if(vis[data[i+k-1]]==0) va++;
		vis[data[i+k-1]]++;
		if(mx < va+(vis[c]==0?1:0)) mx=va+(vis[c]==0?1:0);
	}
	printf("%d",mx);
}