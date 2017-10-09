#include<iostream>
#include<queue>
using namespace std;
int vis[1000000];
struct A {
	int t,p;//time,position
};
queue<A> qu;
int main() {
	int n,k;
	cin>>n>>k;
	A a;
	a.t = 0;
	a.p = k;
	qu.push(a);
	while(!qu.empty()) {
		vis[qu.front().p]=1;
		if(qu.front().p == n) {
			cout<<qu.front().t;
			break;
		} else {
			a.t = qu.front().t+1;
			a.p = qu.front().p/2;
			if(vis[a.p] == 0 && qu.front().p % 2 == 0) 
			qu.push(a);
			a.p = qu.front().p+1;
			if(vis[a.p] == 0) 
			qu.push(a);
			a.p = qu.front().p-1;
			if(vis[a.p] == 0) 
			qu.push(a);
		}
		qu.pop();
	}
}