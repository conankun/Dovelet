#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
struct A {
	string name;
	int minus;
	int correct;
	bool operator<(const A &a) const {
		if(a.correct == correct) return minus < a.minus;
		return correct > a.correct;
	}
};
A arr[1000];
int main() {
	cin>>n;
	int i,j;
	for(i=0;i<n;i++) {
		cin>>arr[i].name;
		for(j=0;j<4;j++) {
			int a,b;
			cin>>a>>b;
			if(b > 0) {
				arr[i].correct++;
				arr[i].minus+=(a-1)*20+b;
			}
		}
	}
	sort(arr,arr+n);
	cout<<arr[0].name<<" "<<arr[0].correct<<" "<<arr[0].minus;
}