#include<iostream>
#include<string>
using namespace std;
int n;
string s;
string arr[100]={"000000","001111","010011","011100","100110","101001","110101","111010"};
string ans;
int main() {
	cin>>n;
	cin>>s; //n*6
	int d,i,j;
	bool t=false;
	for(d=0;d<n;d++) {
		t=false;
		for(j=0;j<8;j++) {
			int cc=0;
			int cnt=0;
			for(i=6*d;i<6*d+6;i++) {
				if(s[i] != arr[j][cc++]) cnt++;
			}
			if(cnt <= 1) {
				ans+='A'+j;
				t=true;
				break;
			}
		}
		if(!t) {
			cout<<d+1;
			return 0;
		}
	}
	cout<<ans;
}