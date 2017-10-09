#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m;
vector<int> v[1111111];
queue<int> qu;
int vis[1111111];
int bfs(int start,int end) {
    qu.push(start);
    for(int i=1;i<=n;i++) vis[i]=0;
    while(!qu.empty()) {
        int c = qu.front();
        vis[c]=1;
        qu.pop();
        if(end == c) {
            return 1;
        }
        for(int i=0;i<v[c].size();i++) {
            if(vis[v[c][i]] == 0) {
                qu.push(v[c][i]);
            }
        }
    }
    return 0;
}
int main() {
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
    }
    int a,b;
    scanf("%d%d",&a,&b);
    int bfs1 = bfs(a,b);
    if(bfs1) {
        printf("yes");
    } else if(bfs(b,a)) {
        printf("no");
    } else {
        printf("unknown");
    }
    
}