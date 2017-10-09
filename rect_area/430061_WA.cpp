#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
struct A {
	double x,y;
};
struct pos {
	double x1,x2,y1,y2;
};
A arr[2000][2000]={0};
pos rects[2000]={0};
double xpos[10000]={0};
int in1=0;
double ypos[10000]={0};
int in2=0;
double sum=0.00;
int main() {
	cin>>n;
	for(int i=0;i<n;i++) {
		double a,b,c,d;
		cin>>a>>b>>c>>d;
		xpos[in1++]=a;
		ypos[in2++]=b;
		xpos[in1++]=a+c;
		ypos[in2++]=b+d;
		rects[i].x1 = a;
		rects[i].x2 = a+c;
		rects[i].y1 = b;
		rects[i].y2 = b+d;
	}
	sort(xpos,xpos+in1);
	sort(ypos,ypos+in2);
	int t=in1;
	for(int i=0;i<t;i++) {
		if(xpos[i] == xpos[i-1]) {
			xpos[i] = 2147483647;
			in1--;
		}
	}
	int t2=in2;
	for(int i=0;i<t2;i++) {
		if(ypos[i] == ypos[i-1]) {
			ypos[i] = 2147483647;
			in2--;
		}
	}
	//재정렬
	sort(xpos,xpos+t);
	sort(ypos,ypos+t2);
	for(int i=0;i<in1;i++) {
		for(int j=0;j<in2;j++) {
			arr[i][j].x = xpos[i];
			arr[i][j].y = ypos[j];
		}
	}
	for(int i=0;i<in1-1;i++) {
		for(int j=0;j<in2-1;j++) {
			for(int k=0;k<n;k++) {
				if(rects[k].x1 <= arr[i][j].x && rects[k].x2 >= arr[i+1][j+1].x && rects[k].y1 <= arr[i][j].y && rects[k].y2 >= arr[i+1][j+1].y) {
					sum+=(arr[i+1][j+1].y-arr[i][j].y)*(arr[i+1][j+1].x-arr[i][j].x);
					break;
				}
			}
		}
	}
printf("%.1f",sum);	
}