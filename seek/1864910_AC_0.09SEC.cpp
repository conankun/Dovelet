#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
vector<int> P(const string &str) {
	int m = str.size();
	vector<int> pi(m, 0);
	int begin = 1, match = 0;
	while (begin + match < m) {
		if (str[begin + match] == str[match]) {
			match++;
			pi[begin + match - 1] = match;
		}
		else {
			if (match == 0) begin++;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
	return pi;
}
vector<int> answer(vector<int> pi, const string &str) {
	int k = str.size();
	vector<int> ans;
	while (k>0) {
		ans.push_back(k);
		k = pi[k - 1];
	}
	return ans;
}
int main() {
	string str;//, str2;
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin >> str ;//>> str2;
	//str += str2;
	vector<int> ve = answer(P(str), str);
	int i;
	for (i = ve.size() - 1; i >= 0; i--) {
		cout << ve[i] << " ";
	}
}