#include<iostream>
#include<stack>
using namespace std;
int n,m;
char c[1000];
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) {
		stack<char> st;
		cin>>m;
		cin>>&c[1];
		bool t=true;
		for(j=1;j<=m;j++) {
			if(c[j]=='>') st.push(c[j]);
			else {
				if(!st.empty() && st.top()=='>') st.pop();
				else {
					t=false;
					break;
				}
			}
		}
		if(t&&st.empty()) printf("legal\n");
		else printf("illegal\n");
	}
}