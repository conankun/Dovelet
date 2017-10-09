#include<iostream>
using namespace std;
char isbn[100];
int value[100];
int gg[100];
int main() {
	int i;
	cin>>isbn;
	int g=10;
	int ind;
	for(i=0;i<10;i++) {
		if(isbn[i] == '?') {
			ind = i;
		} else {
			if(isbn[i] == 'X') value[i] = 10*g;
			else value[i] = (isbn[i]-48)*g;
		}
		gg[i] = g;
		g--;
	}
	int sum=0;
	for(i=0;i<10;i++) {
		sum+=value[i];
	}
	//sum%11;
	g = gg[ind];
	int l = ind == 9 ? 10 : 9;
	for(i=0;i<=l;i++) {
		if((sum+(g*i))% 11 == 0) {
			if(i == 10) cout<<"X";
			else cout<<i;
			return 0;
		}
	}
	cout<<-1;
}