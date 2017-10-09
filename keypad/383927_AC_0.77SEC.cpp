#include<iostream>
#include<vector>
using namespace std;
struct A {
	int back;
	int value;
};
A dp[100][100];
char key[100];
char ch[100];
int num[100];
int sum[100][100];
int n,m;
vector<int> back[100];

int max(int a,int b) {
	if(a > b) return a;
	return b;
}
int main() {
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>key[i];
	for(i=1;i<=m;i++) cin>>ch[i];
	for(i=1;i<=m;i++) cin>>num[i];
	for(i=1;i<=m;i++) {
		int cnt=0;
		int s=0;
		for(j=i;j<=m;j++) {
			s+=num[j]*++cnt;
			sum[i][j] = s;
		}
	}
	for(i=1;i<=n;i++) {
		for(j=i;j<=m;j++) {
			int mn=2147483647;
			int ind=0;
			for(k=i-1;k<j;k++) {
				if(dp[i-1][k].value+sum[k+1][j] < mn) {
					mn = dp[i-1][k].value+sum[k+1][j];
					ind = k;
				}
			}
			if(i == 1) {
				dp[i][j].value = sum[1][j];
				dp[i][j].back = 0;
			} else {
				dp[i][j].back = ind;
				dp[i][j].value = mn;
			}
		}
	}
	j=m;
	i=n;
	while(i > 0) {
		for(k=dp[i][j].back+1;k<=j;k++) {
			back[i].push_back(k);
		}
		j = dp[i][j].back;
		i--;
	}
	for(i=1;i<=n;i++) {
		cout<<key[i]<<": ";
		for(j=0;j<back[i].size();j++) {
			cout<<ch[back[i][j]];
		}
		cout<<endl;
	}
}