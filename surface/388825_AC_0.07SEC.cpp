#include<iostream>
using namespace std;
char a[100][100];
int backs[100];
int n;
int main() {
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) {
		scanf("\n");
		gets(a[i]);
	}
	int mn=214748300;
	for(i=1;i<=n;i++) {
		int sind=26;
		for(j=1;j<=25;j++) {
			if(a[i][j] == 32) {
				sind = j;
				break;
			}
		}
		int cnt=0;
		for(j=sind;j<=25;j++) {
			cnt++;
			if(a[i][j+1] == 'X') break;
		}
		if(cnt < mn) mn = cnt;
		backs[i] = cnt;
	}
	int sum=0;
	for(i=1;i<=n;i++) sum+=backs[i]-mn;
	cout<<sum;
}