#include<iostream> 
#include<algorithm> 
using namespace std; 
int map[1000][1000]={0}; 
int n,s,e; 
int main() { 
    cin>>n>>s>>e; 
    for(int i=0;i<1000;i++) fill(map[i],map[i]+1000,99999999); 
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=n;j++) { 
            cin>>map[i][j]; 
        } 
    } 
    for(int k=1;k<=n;k++) { 
        for(int i=1;i<=n;i++) { 
            for(int j=1;j<=n;j++) { 
                map[i][j] = min(map[i][j],map[i][k]+map[k][j]); 
            } 
        } 
    } 
    cout<<map[s][e]; 
} 
 
