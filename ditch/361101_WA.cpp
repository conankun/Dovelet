#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct A {
	int weight,ind;
	int path[300],index;
	bool operator<(const A &a) const {
		return ind < a.ind;
	}
};
priority_queue<A> qu;
int n,m;
int t;
int cn[300][300];
int vis[300];
int main() {
	int i,j;
	cin>>n>>m;
	t=n;
	while(t--) {
		int a,b,c;
		cin>>a>>b>>c;
		cn[a][b]=c;
	}
	A a;
	a.weight = 99999999;
	a.ind = 1;
	a.path[0]=1;
	a.index=1;
	qu.push(a);
	vis[1]=1;
	int sum=0;
	while(!qu.empty()) {
		A b = qu.top();
		qu.pop();
		if(b.ind == m) {
			for(i=0;i<b.index-1;i++) {
				cn[b.path[i]][b.path[i+1]] -= b.weight;
				cn[b.path[i+1]][b.path[i]] += b.weight;
				vis[b.path[i]]=0;
				vis[b.path[i+1]]=0;
			}
			sum+=b.weight;
			vis[m]=0;
		} else {
			for(i=1;i<=m;i++) {
				if(vis[i] == 0 && cn[b.ind][i] > 0) {
					vis[i]=1;
					a.ind = i;
					for(j=0;j<b.index;j++) {
						a.path[j] = b.path[j];
					}
					a.index = b.index;
					a.path[a.index++]=i;
					a.weight = min(b.weight,cn[b.ind][i]);
					qu.push(a);
				}
			}
		}
	}
	cout<<sum;
}