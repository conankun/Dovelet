#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
char s[100];
int dp[100][100];
int len;
stack<char> st;
bool chk() {
	int i;
	for(i=1;;i++) {
		if(s[i] == 0) break;
		else len++;
	}
	for(i=1;i<=len;i++) {
		if(s[i] == '(' || s[i] == '[') {
			st.push(s[i]);
		} else {
			if(s[i] == ')' || s[i] == ']') {
				if(st.empty()) return false;
			}
			if(s[i] == ')' && st.top() == '(') {
				st.pop();
			} else if(s[i] == ']' && st.top() == '[') {
				st.pop();
			} else {
				return false;
			}
		}
	}
	if(!st.empty()) return false;
	return true;
}
void dynamic() {
	int d,i,j,k;
	for(d=1;d<=len;d++) {
		for(i=1;i<=len-d+1;i++) {
			j=i+d-1;
			if(s[i] == '(' && s[j] == ')') {
				dp[i][j]=dp[i+1][j-1]*2;
				if(j-i == 1) {
					dp[i][j]=2;
				}
			} else if(s[i] == '[' && s[j] == ']') {
				dp[i][j]=dp[i+1][j-1]*3;
				if(j-i == 1) {
					dp[i][j]=3;
				}
			} 
			if((s[i] == '(' || s[i] == '[') && (s[j] == ']' || s[j] == ')') && dp[i][j] == 0) {
				for(k=i+1;k<=j-1;k++) {
					if(dp[i][k] > 0 && dp[k+1][j] > 0) {
						dp[i][j] = dp[i][k]+dp[k+1][j];
						break;
					}
				}
			}
		}
	}
}
int main() {
	scanf("%s",&s[1]);
	bool ok=chk();
	if(!ok) {
		cout<<0;
	} else {
		dynamic();
		cout<<dp[1][len];
	}
}