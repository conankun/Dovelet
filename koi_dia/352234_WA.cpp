#include<iostream>
using namespace std;
struct A {
	int x,y;
};
int n,m,t,k;
int i,j;
A pos[10000]={0};
A posarr[100000]={0};
int ind=0;
int main() {
	cin>>n>>m>>t>>k;
	for(i=0;i<t;i++) cin>>pos[i].x>>pos[i].y;
	for(i=0;i<t;i++) {
		for(j=0;j<t;j++) {
			if(pos[j].y >= k && n-pos[i].x >= k) {
				posarr[ind].x = pos[i].x;
				posarr[ind++].y = pos[j].y;
			}
		}
		for(j=0;j<t;j++) {
			if(pos[i].y >= k && n-pos[j].x >= k) {
				posarr[ind].y = pos[i].y;
				posarr[ind++].x = pos[j].x;
			}
		}
	}
	A rectpos;
	int c=0;
	for(i=0;i<ind;i++) {
		int cnt=0;
		for(j=0;j<t;j++) {
			if(pos[j].x - posarr[i].x >= 0 && pos[j].x - posarr[i].x <= k) {
				if(posarr[i].y - pos[j].y >= 0 && posarr[i].y - pos[j].y <= k) {
					cnt++;
				}
			}
		}
		if(cnt > c) {
			rectpos.x = posarr[i].x;
			rectpos.y = posarr[i].y;
			c=cnt;
		}
	}
	cout<<rectpos.x<<" "<<rectpos.y<<endl;
	cout<<c;
}