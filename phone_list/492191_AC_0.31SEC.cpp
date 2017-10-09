#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int node[1000000][100],T,n,N,isLast[1000000];
char nd[1000000];
int main() {
	int d,i,j,k;
	cin>>T;
	for(d=1;d<=T;d++) {
		n=0;
		cin>>N;
		char c[100];
		bool OK=true;
		for(i=1;i<=N;i++) {
			cin>>c;
			int size=strlen(c);
			int nownode=0;
			for(j=0;j<size;j++) {
				if(node[nownode][c[j]-48]==0) {
					for(k=j;k<size;k++) {
						node[nownode][c[k]-48]=++n;
						if(k==size-1) isLast[n]=1;
						nownode=n;
					}
					break;
				} else {
					if(j==size-1) OK=false;
					nownode=node[nownode][c[j]-48];
					if(isLast[nownode]==1) OK=false;
				}
			}
		}
		if(OK) printf("YES\n");
		else printf("NO\n");
		for(i=0;i<=n;i++) for(j=0;j<=10;j++) node[i][j]=0;
		for(i=0;i<=n;i++) isLast[i]=0;
	}
}