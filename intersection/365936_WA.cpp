#include<iostream>
using namespace std;
struct section {
	int xs,ys;
	int xe,ye;
};
section arr[10];
int ind;
int ccw(int ax,int ay,int bx,int by,int cx,int cy) {
	return (bx-ax)*(cy-ay)-(cx-ax)*(by-ay);
}
bool isTrue(section a,section b) {
	int o=ccw(a.xs,a.ys,a.xe,a.ye,b.xs,b.ys);
	int t=ccw(a.xs,a.ys,a.xe,a.ye,b.xe,b.ye);
	bool one;
	bool two;
	if(o < 0) one=true;
	else one=false;
	if(t < 0) two=true;
	else two=false;
	if(one ^ two) {
		return true;
	}
	if(one ^ two) {
		return true;
	}
	return false;
}
int main() {
	int xstart,ystart,xend,yend,xleft,ytop,xright,ybottom;
	cin>>xstart>>ystart>>xend>>yend>>xleft>>ytop>>xright>>ybottom;
	section a;
	if(xright < xleft || ytop > ybottom) {
		int temp = xright;
		xright = xleft;
		xleft = temp;
		temp = ytop;
		ytop = ybottom;
		ybottom = temp;
	}
	//-(위)
	a.xs = xleft;
	a.ys = ytop;
	a.xe = xright;
	a.ye = ytop;
	arr[ind++]=a;
	//-(아래)
	a.xs = xleft;
	a.ys = ybottom;
	a.xe = xright;
	a.ye = ybottom;
	arr[ind++]=a;
	//|(왼쪽)
	a.xs = xleft;
	a.ys = ytop;
	a.xe = xleft;
	a.ye = ybottom;
	arr[ind++]=a;
	//|(오른쪽)
	a.xs = xright;
	a.ys = ytop;
	a.xe = xright;
	a.ye = ybottom;
	arr[ind++]=a;
	int i;
	a.xs = xstart;
	a.ys = ystart;
	a.xe = xend;
	a.ye = yend;
	for(i=0;i<ind;i++) {
		//i번째 사각형의 선분과 선분의 교차유무 확인.
		bool one=isTrue(arr[i],a);
		bool two=isTrue(a,arr[i]);
		if(one && two) {
			cout<<"T";
			return 0;
		}
	}
	cout<<"F";
}