#include<iostream>
using namespace std;
int n;
int map[101][101];
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			cin>>map[i][j];	
		}
	}
	int mx=-1;
	int ind=-1;
	for(i=1;i<=n;i++) {
		int cnt=0;
		for(j=1;j<=n;j++) {
			if(map[i][j] == 3) cnt++;
		}
		if(cnt > mx) {
			mx = cnt;
			ind = i;
		}
	}
	cout<<ind;
}