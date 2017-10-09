#include<iostream> 
using namespace std; 
int n,m,s; 
int map[1001][1001]={0}; 
int dis[1001]={0}; 
int vis[1001]={0}; 
int bt[1001]={0}; 
int main() { 
    cin>>n>>m>>s; 
    for(int i=0;i<m;i++) { 
        int a,b,c; 
        cin>>a>>b>>c; 
        map[a][b]=c; 
    } 
    //dijkstra 
    for(int i=1;i<=n;i++) { 
        if(map[s][i] != 0) { 
            dis[i]=map[s][i]; 
            bt[i]=s; 
        } 
        if(i != s && map[s][i] == 0) dis[i]=99999; 
    } 
    int p=s; 
    for(int i=1;i<=n-1;i++) { 
        int ss; 
        int min=999999; 
        vis[p]=1; 
        for(int j=1;j<=n;j++) { 
            if(dis[j] < min && vis[j] == 0) { 
                min = dis[j]; 
                ss=j; 
            } 
        } 
  
  
        for(int j=1;j<=n;j++) { 
            if(dis[ss]+map[ss][j] < dis[j] && vis[j] == 0 && map[ss][j] != 0) { 
                dis[j]=dis[ss]+map[ss][j]; 
                bt[j]=ss; 
            } 
        } 
        p=ss; 
    } 
    for(int i=1;i<=n;i++) { 
        int arr[1001]={0}; 
        int in=0; 
        int t=i; 
        while(bt[t] != 0) { 
            arr[in++]=bt[t]; 
            t = bt[t]; 
        } 
        for(int j=in-1;j>=0;j--) cout<<arr[j]<<" "; 
        if(in > 0 || i == s) cout<<i<<endl; 
      
    } 
      
} 
 
