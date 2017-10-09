#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n;
int mxsize;
string s[200];
string su[1000];
int idx;
string convert(string ss) {
	int i;
	string s2=ss;
	ss.resize(mxsize);
	int ind=s2.size()-1;
	for(i=mxsize-1;i>=mxsize-1-s2.size();i--) {
		if(ind < 0) break;
		else {
			ss[i]=s2[ind--];
		}
	}
	int sss=mxsize-1-s2.size();
	for(i=0;i<=sss;i++) {
		ss[i]=1;
	}
	return ss;
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
	//무효의 0제거.
	for(i=0;i<idx;i++) {
		bool t=false;
		for(j=0;j<su[i].size();j++) {
			if(su[i][j] != '0') t=true;
			if(!t && su[i][j] == '0' && j != su[i].size()-1) {
				su[i][j]=1;
			}
		}
	}
	for(i=0;i<idx;i++) {
		if(su[i].size() > mxsize) mxsize = su[i].size();
	}
	for(i=0;i<idx;i++) {
		su[i]=convert(su[i]);	
	}
	sort(su,su+idx);
	for(i=0;i<idx;i++) {
		bool t=false;
		for(j=0;j<su[i].size();j++) {
			if(su[i][j] >= '0' && su[i][j] <= '9') {
				cout<<su[i][j];
			}
		}
		cout<<endl;
	}
}