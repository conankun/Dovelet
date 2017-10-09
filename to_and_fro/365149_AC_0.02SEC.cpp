#include<iostream>
using namespace std;
char code[100][200];
int main() {
	int i,j,n;
	cin>>n;
	char c;
	bool t=true;
	int turn=1;
	for(i=1;;i++) {
		if(turn % 2 == 1) {
		for(j=1;j<=n;j++) {
			if(!(cin>>c)) {
				t=false;
				break;
			}
			code[i][j]=c;
		}
		} else {
		for(j=n;j>=1;j--) {
			if(!(cin>>c)) {
				t=false;
				break;
			}
			code[i][j]=c;
		}
		}
		turn++;
		if(!t) break;
	}
	for(i=1;i<=n;i++) {
		for(j=1;;j++) {
			if(code[j][i] == 0) break;
			else {
				cout<<code[j][i];
			}
		}
	}
}