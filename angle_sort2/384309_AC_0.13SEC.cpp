#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
int n;
struct A {
	int ind;
	int x,y;
	bool operator<(const A &a) const {
		if(y == a.y) return x > a.x;
		return y < a.y;
	}
};
A pos[1000];
int vis[1000];
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) {
		cin>>pos[i].x>>pos[i].y;
		pos[i].ind = i;
	}
	sort(pos+1,pos+1+n);
	vis[1]=1;
	cout<<pos[1].ind<<" ";
	A a,b,c;
	a = pos[1];
	for(i=1;i<=n-1;i++) {
		int ind;
		for(j=1;j<=n;j++) {
			if(vis[j] == 0) {
				b = pos[j];
				ind = j;
				break;
			}
		}
		for(j=1;j<=n;j++) {
			c = pos[j];
			if(vis[j] == 0 && (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y) < 0) {
				b = c;
				ind = j;
			} else if(vis[j] == 0 && ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y) == 0 && pos[j].ind < b.ind)) {
				b = c;
				ind = j;
			}
		}
		vis[ind]=1;
		cout<<pos[ind].ind<<" ";
	}
}