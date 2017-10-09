#include<iostream>
#include<stack>
using namespace std;
int n;
int want[1000];
int ind;
stack<int> st;
int main() {
	cin>>n;
	int i,j;
	for(i=0;i<n;i++) cin>>want[i];
	for(i=1;i<=n;i++) {
		st.push(i);
		while(!st.empty()) {
			if(st.top() != want[ind]) break;
			else {
				st.pop();
				ind++;
			}
		}
	}
	if(st.empty()) cout<<"YES";
	else cout<<"NO";
}