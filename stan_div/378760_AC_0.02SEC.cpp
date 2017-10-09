#include<iostream>
#include<string>
using namespace std;
int lookup[100];
int main() {
	int i;
	for(i='0';i<='9';i++) lookup[i] = i-'0';
	for(i='A';i<='Z';i++) lookup[i] = i-'A'+10;
	for(i='a';i<='z';i++) lookup[i] = i-'a'+36;
	string s;
	while(cin >> s) {
		if(s == "end") {
			break;
		}
		int g = 1;
		int sum=0;
		for(i=0;i<s.size();i++) {
			sum=(sum*62+lookup[s[i]])%61;
		}
		if(sum == 0) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}