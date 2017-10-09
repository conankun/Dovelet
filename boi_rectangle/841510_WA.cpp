#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
struct B {
	double x,y;
}arr[2000];
struct A {
	double length;
	B point1,point2,midpoint;
};
double abs(double AA) {
if(AA < 0) return AA*-1;
return AA;
}
A slope[3000000];
bool cmp(A a, A b) {
	if(a.length==b.length) {
		if(a.midpoint.x == b.midpoint.x) {
			return a.midpoint.y < b.midpoint.y;
		}
		return a.midpoint.x < b.midpoint.x;
	}
	return a.length < b.length;
}
double calculate_slope(B a,B b) {
	if(a.y==b.y) {
		return 0;
	} else if(a.x==b.x) return 1000000000000LL;
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
		//	slope[c_pair].slope=calculate_slope(arr[i],arr[j]);
			slope[c_pair].length=calculate_length(arr[i],arr[j]);
			B midpoint;
			slope[c_pair].point1=arr[i];
			slope[c_pair].point2=arr[j];
			midpoint.x = (arr[i].x+arr[j].x)/2;
			midpoint.y = (arr[i].y+arr[j].y)/2;
			slope[c_pair].midpoint=midpoint;
		}
	}
	stable_sort(slope+1,slope+1+c_pair,cmp);
	double mxarea=0;
	for(i=1;i<=c_pair;i++) {
		for(j=i+1;j<=c_pair;j++) {
			if(fabs(slope[i].length - slope[j].length) < 0.0000000001) {
				if(slope[i].midpoint.x==slope[j].midpoint.x && slope[i].midpoint.y==slope[j].midpoint.y) {//if have identical midpoint
				//calculate the area
					
				double deltax=max(slope[i].point1.x,max(slope[i].point2.x,max(slope[j].point1.x,slope[j].point2.x)))-min(slope[i].point1.x,min(slope[i].point2.x,min(slope[j].point1.x,slope[j].point2.x)));
				double deltay=max(slope[i].point1.y,max(slope[i].point2.y,max(slope[j].point1.y,slope[j].point2.y)))-min(slope[i].point1.y,min(slope[i].point2.y,min(slope[j].point1.y,slope[j].point2.y)));
				double totalrect=deltax*deltay;
				double one1 = abs((slope[i].point1.x-slope[j].point1.x)*(slope[i].point1.y-slope[j].point1.y)/2);
				double one2 = abs((slope[i].point1.x-slope[j].point2.x)*(slope[i].point1.y-slope[j].point2.y)/2);
				double two1 = abs((slope[i].point2.x-slope[j].point1.x)*(slope[i].point2.y-slope[j].point1.y)/2);
				double two2 = abs((slope[i].point2.x-slope[j].point2.x)*(slope[i].point2.y-slope[j].point2.y)/2);
				double ara=totalrect-one1-one2-two1-two2;
					if(ara > mxarea)  mxarea=ara;
				} else {i=j-1;break;}
			} else {
				i=j-1;break;
			}
		}
	}
	printf("%0.lf",mxarea);
}