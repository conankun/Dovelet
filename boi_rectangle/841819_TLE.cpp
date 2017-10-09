#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
struct B {
	long long x,y;
}arr[2000];
struct A {
	long long length,midpointx,midpointy;
	B point1,point2;
};
A slope[3000000];
long long max(long long a,long long b) {
	if(a>b) return a;
	return b;
}
long long min(long long a,long long b) {
	if(a<b) return a;
	return b;
}
bool cmp(A a, A b) {

	if(a.midpointx == b.midpointx) {
		if(a.midpointy==b.midpointy) return a.length< b.length;	
		return a.midpointy < b.midpointy;
	}
	return a.midpointx < b.midpointx;
}
long long calculate_length(B a, B b) {
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
long long N;
int main() {
	scanf("%lld",&N);
	long long i,j;
	for(i=1;i<=N;i++) {
		scanf("%lld%lld",&arr[i].x,&arr[i].y);
	}
	long long c_pair=0;
	for(i=1;i<=N;i++) {
		for(j=i+1;j<=N;j++) {
			c_pair++;
			slope[c_pair].length=calculate_length(arr[i],arr[j]);
			slope[c_pair].midpointx = arr[i].x+arr[j].x;
			slope[c_pair].midpointy = arr[i].y+arr[j].y;
			slope[c_pair].point1=arr[i];
			slope[c_pair].point2=arr[j];
		}
	}
	stable_sort(slope+1,slope+1+c_pair,cmp);
	long long mxarea=0;
	j=2;
	for(i=1;i<=c_pair;i++) {
		for(j=i+1;j<=c_pair;j++) {
			if(slope[i].length == slope[j].length) {
				if(slope[i].point1.x+slope[i].point2.x == slope[j].point1.x+slope[j].point2.x && slope[i].point1.y+slope[i].point2.y==slope[j].point1.y+slope[j].point2.y) {//if have identical midpoint
						//calculate the area
							long long deltax=max(slope[i].point1.x,max(slope[i].point2.x,max(slope[j].point1.x,slope[j].point2.x)))-min(slope[i].point1.x,min(slope[i].point2.x,min(slope[j].point1.x,slope[j].point2.x)));
							long long deltay=max(slope[i].point1.y,max(slope[i].point2.y,max(slope[j].point1.y,slope[j].point2.y)))-min(slope[i].point1.y,min(slope[i].point2.y,min(slope[j].point1.y,slope[j].point2.y)));
							long long totalrect=deltax*deltay;
							long long one1 = abs((slope[i].point1.x-slope[j].point1.x)*(slope[i].point1.y-slope[j].point1.y));
							long long one2 = abs((slope[i].point1.x-slope[j].point2.x)*(slope[i].point1.y-slope[j].point2.y));
							long long two1 = abs((slope[i].point2.x-slope[j].point1.x)*(slope[i].point2.y-slope[j].point1.y));
							long long two2 = abs((slope[i].point2.x-slope[j].point2.x)*(slope[i].point2.y-slope[j].point2.y));
							long long ara=totalrect-(one1+one2+two1+two2)/2;
							if(ara > mxarea)  {
								mxarea=ara;
							}
				} else {
					i=j-1;
					break;
				}
			} else {
				//i=j-1;
				break;
			}
		}
	}//분수꼴로바꿔야함
	printf("%lld",mxarea);
}