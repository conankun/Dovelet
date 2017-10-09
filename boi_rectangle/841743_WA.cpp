#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
struct B {
	long long x,y;
}arr[2000];
struct A {
	long long length;
	B point1,point2;
};
A slope[3000000];
bool cmp(A a, A b) {
	if(a.length==b.length) {
		if(a.point1.x+a.point2.x == b.point1.x+b.point2.x) {
			return a.point1.y+a.point2.y < b.point1.y+b.point2.y;
		}
		return a.point1.x+a.point2.x < b.point1.x+b.point2.x;
	}
	return a.length < b.length;
}
long long calculate_length(B a, B b) {
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
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
			slope[c_pair].length=calculate_length(arr[i],arr[j]);
			slope[c_pair].point1=arr[i];
			slope[c_pair].point2=arr[j];
		}
	}
	stable_sort(slope+1,slope+1+c_pair,cmp);
	long long mxarea=0;
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
				} else {i=j-1;break;}
			} else {
				i=j-1;break;
			}
		}
	}//분수꼴로바꿔야함
	printf("%lld",mxarea);
}