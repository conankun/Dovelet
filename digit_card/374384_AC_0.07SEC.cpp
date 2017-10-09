#include<iostream>
#include<string>
using namespace std;
string r[100]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34"};
string s;
string a;
int dp[10000];
int main() {
	cin>>a;
	s+=" ";
	s+=a;
	int i,j,k;
	dp[0]=1;
	for(i=0;i<s.size();i++) {
		if(dp[i] != 0)
		for(j=1;j<=34;j++) {
			bool t=true;
			int cc=0;
			for(k=i+1;k<=i+r[j].size();k++) {
				if(r[j][cc] != s[k]) t=false;
				cc++;
			}
			if(t) {
				dp[i+r[j].size()]+=dp[i];
			}
		}
	}
	cout<<dp[s.size()-1];
}