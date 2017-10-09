#include<iostream>
using namespace std;
int keyboard[1001][1001];
int n;
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) {
		char c;
		int a,b;
		cin>>c>>a>>b;
		for(j=a;j<b;j++) {
			keyboard[j][c-'A']=!keyboard[j][c-'A'];
		}
	}
	for(i=0;i<=1000;i++) {
		int sum=0;
		for(j=0;j<='Z'-'A';j++) {
			sum+=keyboard[i][j];
		}
		if(sum > 0) {
			cout<<(char)('A'+sum-1);
		}
	}
}