#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
int n;
struct A {
	int ind;
	int x,y;
	double angle;
	bool operator<(const A &a) const {
		if(fabs(a.angle-angle) < 0.00000001) {
			return ind < a.ind;
		}
		return angle < a.angle;
	}
};
bool cmp(A a,A b) {
	if(fabs(a.angle-b.angle) < 0.00000001) {
		return a.ind < b.ind;
	}
	return a.angle > b.angle;	
}
vector<A> first;
vector<A> second;
vector<A> third;
vector<A> fourth;
int main() {
	cin>>n;
	int i;
	for(i=1;i<=n;i++) {
		A a;
		cin>>a.x>>a.y;
		a.angle = (double)abs(a.y)/(abs(a.x)+abs(a.y));
		a.ind = i;
		if(a.x >= 0 && a.y >= 0) {
			first.push_back(a);
		} else if(a.x < 0 && a.y >= 0) {
			second.push_back(a);
		} else if(a.x < 0 && a.y < 0) {
			third.push_back(a);
		} else {
			fourth.push_back(a);
		}
	}
	sort(first.begin(),first.end());
	sort(second.begin(),second.end(),cmp);//
	sort(third.begin(),third.end());
	sort(fourth.begin(),fourth.end(),cmp);//
	for(i=0;i<first.size();i++) cout<<first[i].ind<<" ";
	for(i=0;i<second.size();i++) cout<<second[i].ind<<" ";
	for(i=0;i<third.size();i++) cout<<third[i].ind<<" ";
	for(i=0;i<fourth.size();i++) cout<<fourth[i].ind<<" ";
}