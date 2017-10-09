#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	bool a=false;
	while(cin>>str) {
		if(str=="What") {
			a=true;
			cout<<"Forty-two ";
			continue;
		}
		if(str[str.length()-1]=='.' || str[str.length()-1]=='?') {
			str[str.length()-1]='.';
			if(a) {
				cout<<str;
				cout<<endl;
			}
			a=false;
		}
		if(a) cout<<str<<" ";
	}
}