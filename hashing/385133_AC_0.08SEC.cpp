#include<iostream>
#include<string>
using namespace std;
string s;
int main() {
	cin>>s;
	int i;
	int sum=0;
	int a=0,b=0,c=0;
	int g=1;
	for(i=0;i<s.size();i++) {
		if(s[i] == '$') break;
		a+=(s[i]-48)*g;
		g*=10;
	}
	i++;
	for(;i<s.size();i++) {
		if(s[i] == '$') break;
	}
	i++;
	int j=i-2;
	g=1;
	for(;;j--) {
		if(s[j] == '$') break;
		c+=(s[j]-48)*g;
		g*=10;
	}
	g=1;
	for(;i<s.size();i++) {
		b+=(s[i]-48)*g;
		g*=10;
	}
	cout<<a+b+c;
}