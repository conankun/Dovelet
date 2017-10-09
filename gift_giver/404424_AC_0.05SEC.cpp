#include<iostream>
#include<string>
#include<map>
using namespace std;
int n;
map<string,int> mp;
string names[1000];
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) {
		cin>>names[i];
		mp[names[i]]=0;
	}
	string name;
	while(cin>>name) {
		int a,b;
		cin>>a>>b;
		if(b != 0)
		mp[name]-=(a/b)*b;
		for(i=1;i<=b;i++) {
			cin>>name;
			if(b != 0)
			mp[name]+=a/b;
		}
	}
	for(i=1;i<=n;i++) {
		cout<<names[i]<<" "<<mp[names[i]]<<endl;
	}
}