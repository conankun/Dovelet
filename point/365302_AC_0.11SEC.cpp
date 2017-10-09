#include<iostream>
#include<stdlib.h>
using namespace std;
int lcd(int a,int b) {
	int gob = a*b;
	int c;
	do {
		c = a%b;
		a = b;
		b = c;
	}while(c!=0);
	return gob/a;
}
int main() {
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int t1 = abs(c-a);
	int t2 = abs(d-b);
	int l = lcd(t1,t2);
	if(l == 0) l++;
	if(t1 == 0) t1++;
	if(t2 == 0) t2++;
	cout<<t1*t2/l+1;
}