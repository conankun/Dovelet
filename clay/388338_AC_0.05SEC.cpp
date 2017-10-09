#include<iostream>
#include<string>
using namespace std;
string names[100];
int v[100];
int n;
int main() {
	int i;
	int sum=0;
	cin>>n;
	for(i=1;i<=n;i++) {
		int a,b,c;
		cin>>a>>b>>c>>names[i];
		v[i] = a*b*c;
		sum+=v[i];
	}
	sum/=n;
	string a;
	string b;
	for(i=1;i<=n;i++) {
		if(v[i] > sum) {
			a = names[i];
		}
		if(v[i] < sum) {
			b = names[i];
		}
	}
	cout<<a<<" took clay from "<<b<<".";
}