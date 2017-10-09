#include<stdio.h>
#include<algorithm>
using namespace std;
struct A {
	int x1,y1,x2,y2;
};
int n;
int x[1000];
int xind;
int y[1000];
int yind;
int pos[1000][1000];
int ind;
int floodfill[1000][1000];
A rect[1000];
int max(int a,int b) {
	if(a>b) return a;
	return b;
}
int main() {
	scanf("%d",&n);
	int k,i,j,l;
	for(k=1;k<=n;k++) {
		int a,b;
		scanf("%d%d",&a,&b);
		for(i=a;i<a+10;i++) {
			for(j=b;j<b+10;j++) {
				floodfill[i][j]=1;
			}
		}
	}
	int ans=0;
	for(i=1;i<=100;i++) {
		for(j=1;j<=100;j++) {
			if(floodfill[i][j]==0) continue;
			int beforehigh=-1;
			int high=-1;
			int mx=0;
			k=j;
			for(l=i;l<=100;l++) {
				if(floodfill[l][k]==0) break;
				high=l-i+1;
				mx = max(mx,high*(k-j+1));
			}
			beforehigh=high;
			for(k=j;k<=100;k++) {
				if(floodfill[i][k]==0) break;
				for(l=i;l<beforehigh+i;l++) {
					if(floodfill[l][k]==0) break;
					high=l-i+1;	
					mx = max(mx,high*(k-j+1));
				}
				if(high < beforehigh) beforehigh = high;
			}
			if(mx > ans) ans = mx;
		}
	}
	printf("%d",ans);
}