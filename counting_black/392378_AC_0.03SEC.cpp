#include<iostream>
#include<string>
using namespace std;
int t;
int map[1000][1000]; //0 : white, 1 : black.
int main() {
	cin>>t;
	int i,j,k;
	for(k=1;k<=t;k++) {
		string s;
		int x,y,l;
		cin>>s>>x>>y>>l;
		if(s == "BLACK") {
			for(i=y;i<=y+l-1;i++) {
				for(j=x;j<=x+l-1;j++) {
					map[i][j] = 1;
				}
			}
		} else if(s == "WHITE") {
			for(i=y;i<=y+l-1;i++) {
				for(j=x;j<=x+l-1;j++) {
					map[i][j] = 0;
				}
			}
		} else {
			int cnt=0;
			for(i=y;i<=y+l-1;i++) {
				for(j=x;j<=x+l-1;j++) {
					if(map[i][j] == 1) cnt++;
				}
			}
			cout<<cnt<<endl;
		}
	}
}