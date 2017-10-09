#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
struct B {
	double x,y;
}arr[2000];
struct A {
	double slope,length;
	B midpoint;
};
A slope[3000000];
bool cmp(A a, A b) {
	if(a.slope==b.slope) {
		return a.length < b.length;
	}
	return a.slope < b.slope;
}
double calculate_slope(B a,B b) {
	if(a.y==b.y) {
		return 0;
	} else if(a.x==b.x) return -1;
	return (a.y-b.y)/(a.x-b.x);
}
double calculate_length(B a, B b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int N;
int main() {
	cin>>N;
	int i,j;
	for(i=1;i<=N;i++) {
		cin>>arr[i].x>>arr[i].y;
	}
	int c_pair=0;
	for(i=1;i<=N;i++) {
		for(j=i+1;j<=N;j++) {
			c_pair++;
			slope[c_pair].slope=calculate_slope(arr[i],arr[j]);
			slope[c_pair].length=calculate_length(arr[i],arr[j]);
			B origins = {-1100000000,-1100000000};
			B midpoint;
			midpoint.x = (arr[i].x+arr[j].x)/2;
			midpoint.y = (arr[i].y+arr[j].y)/2;
			slope[c_pair].midpoint=midpoint;
		}
	}
	sort(slope+1,slope+1+c_pair,cmp);
	double mxarea=0;
	for(i=1;i<=c_pair;i++) {
		for(j=i+1;j<=c_pair;j++) {
			if(slope[i].length == slope[j].length && slope[i].slope == slope[j].slope && (calculate_slope(slope[i].midpoint,slope[j].midpoint)*slope[i].slope == -1)) {
				//calculate the area
				double ara = calculate_length(slope[i].midpoint,slope[j].midpoint)*slope[i].length;
				if(ara > mxarea)  mxarea=ara;
			} else {
				i=j-1;break;
			}
		}
	}
	printf("%.0lf",mxarea);
}