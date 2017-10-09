#include<iostream>
using namespace std;
int map[1000][1000];
int a,b,k;
struct A {
	int r,s,p,t;
};
A arr[1000];
int main() {
	cin>>a>>b>>k;
	int i,j,d;
	for(i=1;i<=k;i++) {
		cin>>arr[i].r>>arr[i].s>>arr[i].p>>arr[i].t;
	}
	int count=0;
	for(d=1;d<=k;d++) {
		A aa = arr[d];
		int sy = aa.r-aa.p/2;
		int sx = aa.s-aa.p/2;
		if(aa.t == 1) count++;
		for(i=sy;i<sy+aa.p;i++) {
			if(i > a) break;
			if(i < 1) continue;
			for(j=sx;j<sx+aa.p;j++) {
				if(j > b) break;
				if(j < 1) continue;
				if(aa.t == 0) {
					map[i][j]=-1;
				} else {
					if(map[i][j] != -1) map[i][j]++;
				}
			}
		}
	}
	int cnt=0;
	for(i=1;i<=a;i++) {
		for(j=1;j<=b;j++) {
			if(map[i][j] == count) cnt++;
		}
	}
	cout<<cnt;
}