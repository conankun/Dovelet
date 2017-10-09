#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
#include<float.h>
using namespace std;
int n;
struct A {
	int x,y;
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
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(i==j) continue;
			double d = abs(points[i].y-points[j].y)/(double)(abs(points[i].x-points[j].x)+abs(points[i].y-points[j].y));
			if(points[i].x > points[j].x) d = 1-d;
			angles[++ind]=d;
		}
	}
	sort(angles+1,angles+ind+1);
	int cnt=0;
	for(i=1;i<=ind;i++) {
		if(!(fabs(angles[i]-angles[i-1]) < 0.000000001)) cnt++;
	}
	cout<<cnt;
}