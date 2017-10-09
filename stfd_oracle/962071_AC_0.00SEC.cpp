#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main() {
	string str;
	bool a=false;
	queue<string> qu;
	while(cin>>str) {
		if(str[str.length()-1]=='.' || str[str.length()-1]=='?') {
			if(str[str.length()-1]=='?') {
				str[str.length()-1]='.';
				qu.push(str);
				while(!qu.empty()) {
					if(qu.front()=="What") cout<<"Forty-two ";
					else cout<<qu.front()<<" ";
					qu.pop();
				}
				cout<<endl;
			} else {
				while(!qu.empty()) qu.pop();
			}
				
		}
		else qu.push(str);
	}
}