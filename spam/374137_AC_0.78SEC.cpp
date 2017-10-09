#include<iostream>
#include<string>
using namespace std;
string spam[100]={"4","|3","(","|)","3","|=","6","#","|","_|","|<","|_","|\\/|","|\\|","0","|0","(,)","|?","5","7","|_|","\\/","\\/\\/","><","-/","2"};
string s;
string sp;
int dp[100000];
int main() {
	int i,j,k;
	cin>>s;
	sp+=" ";
	for(i=0;i<s.size();i++) {
		sp+=spam[s[i]-'A'];
	}
	dp[0]=1;
	for(i=0;i<sp.size();i++) {
		if(dp[i] != 0)
		for(j=0;j<26;j++) {
			bool t=true;
			int cc=0;
			for(k=i+1;k<=i+spam[j].size();k++) {
				if(sp[k] != spam[j][cc]) {
					t=false;
					break;
				}
				cc++;
			}
			if(t && i+spam[j].size() <= sp.size()-1) {
				dp[i+spam[j].size()]+=dp[i];
			}
		}
	}
	cout<<dp[sp.size()-1];
}