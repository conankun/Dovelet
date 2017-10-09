#include<iostream>
using namespace std;
struct A {
	int x,y,z;
};
int ccw(A a,A b,A c) {
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int main() {
	A a,b,c;
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
	if(ccw(a,b,c) == 0 && ccw(b,c,a) == 0 && ccw(c,a,b) == 0) {
		cout<<"yes";
	} else cout<<"no";
}