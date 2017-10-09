#include<iostream>
#include<string>
using namespace std;
int main() {
	int t,n;
	int sum=0;
	int i,j;
	cin>>t>>n;
	for(i=0;i<t;i++) {
		string a;
		int point;
		cin>>a>>point;
		sum+=point;
	}
	cout<<(n-((sum-n)/2))*2;	
}