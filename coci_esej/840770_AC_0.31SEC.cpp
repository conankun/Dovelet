#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	int N;
	cin>>N;
	int i,j;
	int cnt=0;
	for(i=1;i<=N;i++) {
		stack<char> st;
		string s;
		cin>>s;
		for(j=0;j<s.size();j++) {
			if(st.size()==0) st.push(s[j]);
			else if(st.top()==s[j]) st.pop();
			else st.push(s[j]);
		}
		if(st.size()==0) {
			cnt++;
		}
	}
	printf("%d",cnt);
}