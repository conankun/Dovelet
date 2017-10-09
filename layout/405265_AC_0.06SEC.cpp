#include<iostream>
using namespace std;
int m;
int y;
int x;
int y11,x11,mxy;
int main() {
	cin>>m;
	int a,b;
	bool t=false;
	while(cin>>a>>b) {
		if(a == -1 && b == -1) break;
		t=false;
		if(x11+a > m) {
			x11=a;
			if(x11 > x) x = x11;
			y+=mxy;
			mxy=b;
			t=true;
		} else {
			x11+=a;
			if(x11 > x) x = x11;
			if(mxy < b) mxy = b;
		}
	}
	if(x11 > x) x = x11;
	y += mxy;
	cout<<x<<" x "<<y;
}