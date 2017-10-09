#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> path;
stack<int> cir;
int n,e;
int map[300][300];
int deg[300];
void eulerpath(int s) {
	int i,j;
	int c=s;
	cir.push(c);
	bool t=true;
	for(i=1;i<=e+1;i++) {
		int go=-1;
		for(j=1;j<=n;j++) {
			if(map[c][j] == 1) {
				map[c][j]=0;
				map[j][c]=0;
				go=j;
				break;
			}
		}
		if(go==-1) {
			cir.pop();
			path.push_back(c);
			c = cir.top();
		} else {
			cir.push(go);
			c = go;
		}
	}
	while(!cir.empty()) {
		path.push_back(cir.top());
		cir.pop();
	}
	for(i=0;i<path.size();i++) cout<<path[i]<<" ";
}
int main() {
	int i,j;
	cin>>n>>e;
	for(i=0;i<e;i++) {
		int a,b;
		cin>>a>>b;
		map[a][b]=1;
		map[b][a]=1;
		deg[a]++;
		deg[b]++;
	}
	int even=0,odd=0;
	int s=0;
	bool t=true;
	for(i=1;i<=n;i++) {
		int cnt=0;
		for(j=1;j<=n;j++) {
			cnt+=map[i][j];
		}
		if(cnt%2 == 0) even++;
		else {
			if(t) {
				s=i;
				t=false;
			}
			odd++;
		}
	}
	if(!(odd==2 || odd == 0)) { //불가능한 경우.
		cout<<0;
	} else {
		if(odd == 0) { //아무점에서나 시작.
			s=1;
			eulerpath(s);
		} else { //홀수인 점에서 시작.
			eulerpath(s);
		}
	}
}