#include<iostream> 
#include<fstream> 
using namespace std; 
int n; 
int dist[101]={0}; 
int map[101][101]={0}; 
int vis[101]={0}; 
int main() { 
    int n; 
    cin>>n; 
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>map[i][j]; 
    for(int i=1;i<=n;i++) dist[i]=map[1][i]; 
    int p=1; 
    int sum=0; 
    vis[1]=1; 
    for(int i=1;i<=n-1;i++) { 
        int min=2147483647; 
        int b; 
        for(int j=2;j<=n;j++) { 
            if(dist[j] < min && vis[j] != 1) { 
                min=dist[j]; 
                b = j; 
            } 
        } 
        vis[b]=1; 
        for(int j=2;j<=n;j++) { 
            if(map[b][j] < dist[j] && vis[j] != 1) dist[j] = map[b][j]; 
        } 
        p=b; 
    } 
    for(int i=1;i<=n;i++) { 
        sum+=dist[i]; 
    } 
    cout<<sum; 
} 
 
