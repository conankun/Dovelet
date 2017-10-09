#include<iostream>
#include<cstring>
using namespace std;
char s[10000];
int ball=1;
int main() {
	cin>>s;
	int i;
	for(i=0;;i++) {
		if(s[i]==0) break;
		if(s[i]=='A') {
			if(ball==1) ball=2;
			else if(ball==2) ball=1;
		} else if(s[i]=='B') {
			if(ball==2) ball=3;
			else if(ball==3) ball=2;
		} else if(s[i]=='C') {
			if(ball==1) ball=3;
			else if(ball==3) ball=1;
		}
	}
	cout<<ball;
}