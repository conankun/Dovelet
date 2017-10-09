#include<iostream>
#include<queue>
using namespace std;
struct A {
    int s;
    int t;
};
int vis[10000000]={0};
int main() {
    int v;
    queue<A> qu;
    int n;
    cin>>n;
    A a;
    a.s = 1;
    a.t = 0;
    qu.push(a);
    vis[1]=1;
    while(!qu.empty()) {
        int s = qu.front().s;
        int t = qu.front().t;
        if(s == n) {
            v = t;
            break;
        }
        if(vis[s*2] != 1) {
            vis[s*2]=1;
            a.s = s*2;
            a.t = t+1;
            qu.push(a);
        }
        if(vis[s/3] != 1) {
            vis[s/3]=1;
            a.s = s/3;
            a.t = t+1;
            qu.push(a);
        }
        qu.pop();
    }
    cout<<v;
}