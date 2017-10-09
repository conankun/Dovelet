#include<iostream>
#include<vector>
using namespace std;
struct A {
	int back;
	int value;
	int cnt[100];
};
A dp[100][100];
char key[100];
char ch[100];
int num[100];
int n,m;
vector<int> back[100];

int main() {
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>key[i];
	for(i=1;i<=m;i++) cin>>ch[i];
	for(i=1;i<=m;i++) cin>>num[i];
	for(i=1;i<=m;i++) {
		for(j=1;j<=n;j++) {
			if(j==1) {
				dp[i][j] = dp[i-1][j];
				dp[i][j].value = dp[i-1][j].value+(dp[i-1][j].cnt[j]+1)*num[i];
				dp[i][j].cnt[j]++;
				dp[i][j].back = 1;
			} else {
				if(dp[i-1][j-1].value+(dp[i-1][j-1].cnt[j]+1)*num[i] < dp[i-1][j].value+(dp[i-1][j].cnt[j]+1)*num[i]) {
					dp[i][j] = dp[i-1][j-1];
					dp[i][j].value = dp[i-1][j-1].value+(dp[i-1][j-1].cnt[j]+1)*num[i];
					dp[i][j].cnt[j]++;
					dp[i][j].back = j-1;
				} else {
					dp[i][j] = dp[i-1][j];
					dp[i][j].value = dp[i-1][j].value+(dp[i-1][j].cnt[j]+1)*num[i];
					dp[i][j].cnt[j]++;
					dp[i][j].back = j;
				}
			}
		}
	}
	j=1;
	for(i=2;i<=n;i++) {
		if(dp[m][j].value > dp[m][i].value) {
			j = i;
		}
	}
	i=m;
	while(i > 0) {
		back[j].push_back(i);
		j = dp[i][j].back;
		i--;
	}
	for(i=1;i<=n;i++) {
		cout<<key[i]<<": ";
		for(j=back[i].size()-1;j>=0;j--) {
			cout<<ch[back[i][j]];
		}
		cout<<endl;
	}
}