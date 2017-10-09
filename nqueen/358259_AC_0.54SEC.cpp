#include<iostream> 
#include<stdlib.h> 
using namespace std; 
int map[20][20]={0}; // 2 = 퀸 
int vis2[200]={0},vis3[200]={0},vis4[200]={0}; 
int cnt=0; 
int t=0; 
int n; 
void bt(int ns,int y) { 
    if(ns == n) { 
        if(t < 3) { 
            for(int i=1;i<=n;i++) { 
                for(int j=1;j<=n;j++) { 
                    if(map[i][j] == 2) { 
                        cout<<j<<" "; 
                    } 
                } 
            } 
            cout<<endl; 
        } 
        t++; 
        cnt++; 
        return; 
    } 
    for(int i=1;i<=n;i++) { 
            if(vis2[i] == 0 && vis3[i+y-1] == 0 && vis4[abs(n-i)+y] == 0) { 
                vis2[i]=1; 
                vis3[i+y-1] = 1; 
                vis4[abs(n-i)+y]=1; 
                map[y+1][i]=2; 
                bt(ns+1,y+1); 
                map[y+1][i]=0; 
                vis2[i]= 0; 
                vis3[i+y-1] = 0; 
                vis4[abs(n-i)+y]=0; 
            } 
    } 
} 
int main() { 
    cin>>n; 
    bt(0,0); 
    cout<<cnt; 
} 
 
