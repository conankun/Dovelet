#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n;
string s[200];
string su[1000];
unsigned long long sus[1000];
int idx;
unsigned long long convert(string s) {
	int i;
	unsigned long long sum=0;
	unsigned long long g=1;
	for(i=s.size()-1;i>=0;i--) {
		sum+=g*(s[i]-48);
		g*=10;
	}
	return sum;
}
int main() {
	int i,j;
	cin>>n;
	for(i=0;i<n;i++) cin>>s[i];
	for(i=0;i<n;i++) {
		bool t=false;
		for(j=0;j<s[i].size();j++) {
			char a=s[i][j];
			if(a >= '0' && a <= '9') {
				su[idx]+=s[i][j];
				t=true;
			} else if(t) {
				idx++;
				t=false;
			}
		}
		if(t) idx++;
	}
	for(i=0;i<idx;i++) {
		sus[i]=convert(su[i]);
	}
	sort(sus,sus+idx);
	for(i=0;i<idx;i++) cout<<sus[i]<<endl;
}