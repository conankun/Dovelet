#include<iostream> 
#include<queue> 
using namespace std; 
struct aaa{ 
    int pos; 
    int cnt; 
}; 
int main() { 
    int n,m,a,b; 
    queue<aaa> qu; 
    int data[101][101]={0}; 
    int vis[101]={0}; 
    cin>>n>>a>>b>>m; 
    for(int i=0;i<m;i++) { 
        int c,d; 
        cin>>c>>d; 
        data[c][d]=1; 
        data[d][c]=1; 
    } 
    int cnt = 0; 
    struct aaa aaa; 
    aaa.cnt = cnt; 
    aaa.pos = a; 
    qu.push(aaa); 
    int value=-1; 
    while(!qu.empty()) { 
        struct aaa q = qu.front(); 
        if(q.pos == b) { 
            value=q.cnt; 
            break; 
        } 
        vis[q.pos] = 1; 
        for(int i=1;i<=n;i++) { 
            if(vis[i] == 0 && data[q.pos][i] == 1) { 
                struct aaa b; 
                b.pos = i; 
                b.cnt = q.cnt+1; 
                qu.push(b); 
            } 
        } 
        qu.pop(); 
    } 
    cout<<value; 
} 
 
