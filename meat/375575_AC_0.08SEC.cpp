#include<iostream>
using namespace std;
int n;
int meat[1000];
int main() {
	cin>>n;
	int i;
	int sum=0;
	for(i=1;i<=n;i++) {
		cin>>meat[i];
		sum+=meat[i];
	}
	int s=0;
	for(i=1;i<=n;i++) {
		s+=meat[i];
		if(s == sum-s) {
			cout<<"Sam stops at position "<<i<<" and Ella stops at position "<<i+1<<".";
			return 0;
		}
	}
	cout<<"No equal partitioning.";
}