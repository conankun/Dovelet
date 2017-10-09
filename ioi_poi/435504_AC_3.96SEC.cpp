#include<iostream>
#include<algorithm>
using namespace std;
int point[2011]={0};
struct A {
	int index;
	int point;
	int correct;
	int problem[2001];
};
bool cmp(A a,A b) {
	if(a.point == b.point) {
		if(a.correct == b.correct) {
			return a.index < b.index;
		} else return a.correct > b.correct;
	}
	return a.point > b.point;
}
A arr[2001]={0};
int n,t,p;
int main() {
	scanf("%d %d %d",&n,&t,&p);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=t;j++) {
			int a;
			scanf("%d",&a);
			if(a == 0) point[j]++;
			arr[i].problem[j] = a;
			if(a == 1) arr[i].correct++;
		}
		arr[i].index = i;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=t;j++) {
			arr[i].point+=(point[j]*arr[i].problem[j]);
		}
	}
	sort(arr+1,arr+n+1,cmp);
	for(int i=1;i<=n;i++) {
		if(arr[i].index == p) {
			printf("%d %d",arr[i].point,i);
			break;
		}
	}
}