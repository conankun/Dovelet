#include<iostream> 
using namespace std; 
int n,m,x; 
int map[1001][1001]={0}; 
int map2[1001][1001]={0}; 
int main() { 
    cin>>n>>m>>x; 
    for(int i=0;i<m;i++) { 
        int a,b,c; 
        cin>>a>>b>>c; 
        map[a][b]=c; 
    } 
    int dis1[1001]={0}; 
    int dis2[1001]={0}; 
    int vis1[1001]={0}; 
    int vis2[1001]={0}; 
    int p = x; 
    for(int i=1;i<=n;i++) { 
        if(map[p][i] != 0) { 
            dis1[i] = map[p][i]; 
        } else dis1[i]=99999999; 
    } 
    for(int i=1;i<=n-1;i++) { 
        int min=2147483647; 
        int b; 
        vis1[p]=1; 
        for(int j=1;j<=n;j++) { 
            if(dis1[j] < min && vis1[j] != 1) { 
                min = dis1[j]; 
                b = j; 
            } 
        } 
        for(int j=1;j<=n;j++) { 
            if(dis1[j] > dis1[b]+map[b][j] && vis1[j] != 1 && map[b][j] != 0) { 
                dis1[j] = dis1[b]+map[b][j]; 
            } 
        } 
        p=b; 
    } 
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=n;j++) { 
            if(map[i][j] != 0) { 
                map2[j][i] =map[i][j]; 
            } 
        } 
    } 
    p = x; 
    for(int i=1;i<=n;i++) { 
        if(map2[p][i] != 0) { 
            dis2[i] = map2[p][i]; 
        } else dis2[i]=99999999; 
    } 
    for(int i=1;i<=n-1;i++) { 
        int min=2147483647; 
        int b; 
        vis2[p] = 1; 
        for(int j=1;j<=n;j++) { 
            if(dis2[j] < min && vis2[j] != 1) { 
                min = dis2[j]; 
                b = j; 
            } 
        } 
        for(int j=1;j<=n;j++) { 
            if(dis2[j] > dis2[b]+map2[b][j] && vis2[j] != 1 && map2[b][j] != 0) { 
                dis2[j] = dis2[b]+map2[b][j]; 
            } 
        } 
        p=b; 
    } 
    int mx=0; 
    for(int i=1;i<=n;i++) { 
        if(dis1[i]+dis2[i] > mx && dis1[i] != 99999999 && dis2[i] != 99999999) mx = dis1[i]+dis2[i]; 
    } 
    cout<<mx; 
} 
 
