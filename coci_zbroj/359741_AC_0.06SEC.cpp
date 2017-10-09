#include<iostream>
#include<cmath>
using namespace std;
int a,b;
void convertmax() {
	int n=a;
	int t=0;
	int m=b;
	while(n > 0) {
		if(n%10 == 5) {
			a+=pow(10,(double)t);
		}
		t++;
		n/=10;
	}
	t=0;
	while(m > 0) {
		if(m%10 == 5) {
			b+=pow(10,(double)t);
		}
		t++;
		m/=10;
	}
}
void convertmin() {
	int n=a;
	int t=0;
	int m=b;
	while(n > 0) {
		if(n%10 == 6) {
			a-=pow(10,(double)t);
		}
		t++;
		n/=10;
	}
	t=0;
	while(m > 0) {
		if(m%10 == 6) {
			b-=pow(10,(double)t);
		}
		t++;
		m/=10;
	}
}
int main() {
	cin>>a>>b;
	convertmin();
	cout<<a+b;
	convertmax();
	cout<<" "<<a+b;
}