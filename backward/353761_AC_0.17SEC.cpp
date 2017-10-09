#include<iostream>
using namespace std;
int n,k;
int back[11][11]={0};
int vis[3000]={0};
int in=0;
bool ok = false;
void hap(int level) {
    if(level < n) {
    for(int i=0;i<level;i++) {
        back[level][i]=back[level+1][i]+back[level+1][i+1];
    }
    }
    if(level == 1 &&  back[1][0] == k) {
        ok=true;
        return;
    }
     
    if(level > 1)
    hap(level-1);
}
void bt(int c) {
    if(c == 0) {
        hap(n);
        if(ok) {
            for(int i=0;i<n;i++) cout<<back[n][i]<<" ";
            return;
        }
    } else {
        for(int i=0;i<n;i++) {
            if(vis[i+1] != 1) {
                vis[i+1]=1;
                back[n][in]=i+1;
                in++;
                if(!ok) bt(c-1);
                else return;
                vis[i+1]=0;
                back[n][in-1]=0;
                in--;
            }
        }
    }
}
int main() {
    cin>>n>>k;
    bt(n);
}