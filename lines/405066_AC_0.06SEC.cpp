#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
#include<float.h>
using namespace std;
int n;
struct A {
	int x,y;
	bool operator<(const A &a) const {
		return x < a.x;	
	}
};
A points[10000];
double angles[100000];
int ind;
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) {
		cin>>points[i].x>>points[i].y;
	}
	sort(points+1,points+1+n);
	for(i=1;i<=n;i++) {
		for(j=i+1;j<=n;j++) {
			double d = abs(points[i].y-points[j].y)/(double)(abs(points[i].x-points[j].x)+abs(points[i].y-points[j].y));
			if(points[i].y > points[j].y) d = 2-d;
      			angles[++ind]=d;
		}
	}
	sort(angles+1,angles+ind+1);
	int cnt=1;
	for(i=2;i<=ind;i++) {
		if(!(fabs(angles[i]-angles[i-1]) < 0.000000001)) cnt++;
	}
	cout<<cnt;
}