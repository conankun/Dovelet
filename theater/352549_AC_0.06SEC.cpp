#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
using namespace std;
struct pos {
	int y,x;
	double dis;
};
bool cmp(pos a,pos b) {
	if(a.y == b.y && a.dis == b.dis) return a.x < b.x;
	if(a.dis == b.dis) return a.y < b.y;
	return a.dis < b.dis;
}
int map[500][500];
int w,r;
int i,j;
pos arr[100000];
int ind=0;
int main() {
	cin>>w>>r;
	//(1,(w+1)/2)-->(y,x)
	for(i=1;i<=r;i++) {
		for(j=1;j<=w;j++) {
			arr[ind].y = i;
			arr[ind].x = j;
			int a = abs(1-i);
			int b=abs(((w+1)/2)-j);
			arr[ind++].dis = sqrt((double)(a*a) + (double)(b*b));
		}
	}
	int t=1;
	sort(arr,arr+ind,cmp);
	for(i=0;i<ind;i++) {
		map[arr[i].y][arr[i].x]=t;
		t++;
	}
	for(i=r;i>=1;i--) {
		for(j=1;j<=w;j++) {
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}