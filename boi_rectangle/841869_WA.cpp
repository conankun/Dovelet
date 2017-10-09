#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
struct B {
	int x,y;
}arr[2000];
struct A {
	long long length,midpointx,midpointy;
	B point1,point2;
};
A slope[3000000];
int index[3000000];
long long max(long long a,long long b) {
	if(a>b) return a;
	return b;
}
long long min(long long a,long long b) {
	if(a<b) return a;
	return b;
}
bool cmp(int a,int b) {

	if(slope[a].midpointx == slope[b].midpointx) {
		if(slope[a].midpointy==slope[b].midpointy) return slope[a].length< slope[b].length;	
		return slope[a].midpointy < slope[b].midpointy;
	}
	return slope[a].midpointx < slope[b].midpointx;
}
long long calculate_length(B a, B b) {
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
long long N;
int main() {
	scanf("%lld",&N);
	long long i,j;
	for(i=1;i<=N;i++) {
		scanf("%d%d",&arr[i].x,&arr[i].y);
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
			index[c_pair]=c_pair;
		}
	}
	sort(index+1,index+1+c_pair,cmp);
	long long mxarea=0;
	j=2;
	long long deltax,deltay,totalrect,one1,one2,two1,two2,ara;
	for(i=1;i<=c_pair;i++) {
		for(j=i+1;j<=c_pair;j++) {
			if(slope[index[i]].length == slope[index[j]].length) {
				if(slope[index[i]].point1.x+slope[index[i]].point2.x == slope[index[j]].point1.x+slope[index[j]].point2.x && slope[index[i]].point1.y+slope[index[i]].point2.y==slope[index[j]].point1.y+slope[index[j]].point2.y) {//if have identical midpoint
						//calculate the area
							deltax=max(slope[index[i]].point1.x,max(slope[index[i]].point2.x,max(slope[index[j]].point1.x,slope[index[j]].point2.x)))-min(slope[index[i]].point1.x,min(slope[index[i]].point2.x,min(slope[index[j]].point1.x,slope[index[j]].point2.x)));
							deltay=max(slope[index[i]].point1.y,max(slope[index[i]].point2.y,max(slope[index[j]].point1.y,slope[index[j]].point2.y)))-min(slope[index[i]].point1.y,min(slope[index[i]].point2.y,min(slope[index[j]].point1.y,slope[index[j]].point2.y)));
							totalrect=deltax*deltay;
							one1 = abs((slope[index[i]].point1.x-slope[index[j]].point1.x)*(slope[index[i]].point1.y-slope[index[j]].point1.y));
							one2 = abs((slope[index[i]].point1.x-slope[index[j]].point2.x)*(slope[index[i]].point1.y-slope[index[j]].point2.y));
							two1 = abs((slope[index[i]].point2.x-slope[index[j]].point1.x)*(slope[index[i]].point2.y-slope[index[j]].point1.y));
							two2 = abs((slope[index[i]].point2.x-slope[index[j]].point2.x)*(slope[index[i]].point2.y-slope[index[j]].point2.y));
							ara=totalrect-(one1+one2+two1+two2)/2;
							if(ara > mxarea)  {
								mxarea=ara;
							}
				} else {
					i=j-1;
					break;
				}
			} else {
				break;
			}
		}
	}//분수꼴로바꿔야함
	printf("%lld",mxarea);
}