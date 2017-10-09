#include<iostream>
#include<algorithm>
using namespace std;
int r,c;
struct A {
	int value;
	int index;
	bool operator<(const A &a) const {
		return value > a.value;
	}
};
A root[1000];
int ranks[1000];
char map[1000][1000];
int main() {
	cin>>r>>c;
	int i,j,k;
	for(i=1;i<=r;i++) {
		for(j=1;j<=c;j++) cin>>map[i][j];
		for(j=c;j>=1;j--) {
			if(map[i][j] != 'S' && map[i][j] != '.' && map[i][j] != 'F') {
				if(root[map[i][j]-'0'].value < j) root[map[i][j]-'0'].value = j;
				root[map[i][j]-'0'].index = map[i][j]-'0';
				break;
			}
		}
	}
	sort(root+1,root+1+100);
	int rank=0;
	for(i=1;i<=100;i++) {
		if(root[i].value > 0) {
			if(root[i].value != root[i-1].value) rank++;
			ranks[root[i].index] = rank;	
		}
	}
	for(i=1;i<=100;i++) {
		if(ranks[i] > 0) cout<<ranks[i]<<endl;
	}
}