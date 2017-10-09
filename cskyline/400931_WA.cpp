#include<iostream>
#include<stack>
using namespace std;
int height[100000];
stack<int> st;
int main() {
	int i;
	int n,w;
	cin>>n>>w;
	int x;
	for(i=1;i<=n;i++) {
		cin>>x>>height[i];
	}
	int cnt=0;
	for(i=1;i<=n;i++) {
		bool t=false;
		while(!st.empty()) {
			if(st.top() > height[i]) {
				st.pop();
			} else {
				if(st.top() == height[i] || st.top() == 0) t=true;
				break;
			}
		}
		if(t ||(st.empty() && height[i] != 0)) cnt++;
		st.push(height[i]);
	}
	cout<<cnt;
}