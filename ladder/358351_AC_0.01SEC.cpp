#include<iostream> 
using namespace std; 
int ladder[30][1000]={0}; 
char ladderdown(int s) { 
    int t=s; 
    for(int i=1;i<=1000;i++) { 
        int s=t; 
        if(ladder[t][i] == 1) { 
            s = t+1; 
        } else if(ladder[t-1][i] == 1) { 
            s = t-1; 
        } 
        t=s; 
    } 
    return 'A'+(t-1); 
} 
int main() { 
    int n,m; 
    cin>>n>>m; 
    for(int i=0;i<m;i++) { 
        int a; 
        cin>>a; 
        ladder[a][i+1]=1; 
    } 
    for(int i=1;i<=n;i++) { 
        cout<<i<<" "<<ladderdown(i)<<endl; 
    } 
} 
 
