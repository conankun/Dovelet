#include<iostream> 
using namespace std; 
int n; 
int map[200][200]={0}; 
int dis[200]={0}; 
int vis[200]={0}; 
int i,j; 
int main() { 
    cin>>n; 
    for( i=0;i<n;i++) { 
        char a,b; 
        int c; 
        cin>>a>>b>>c; 
        if(c < map[a][b] || map[a][b] == 0) map[a][b]=c; 
        if(c < map[b][a] || map[b][a] == 0) map[b][a]=c; 
    } 
    for( i=0;i<200;i++) { 
        if(map['Z'][i] != 0) { 
            dis[i] = map['Z'][i] ; 
        } else dis[i] = 99999999; 
    } 
    int p = 'Z'; 
    dis['Z']=0; 
    for( i=1;i<200-1;i++) { 
        int b; 
        int min=100000000; 
        vis[p]=1; 
        for( j=0;j<200;j++) { 
            if(dis[j] < min && vis[j] != 1) { 
                min = dis[j]; 
                b = j; 
            } 
        } 
        for( j=0;j<200;j++) { 
            if(dis[j] > dis[b]+map[b][j] && vis[j] != 1 && map[b][j] != 0) { 
                dis[j] = dis[b]+map[b][j]; 
            } 
        } 
        p=b; 
    } 
    int min=99999999; 
    int in; 
    for( i=0;i<200;i++) { 
        if(dis[i] < min && i != 'Z' && i >= 'A' && i <= 'Z') { 
            min = dis[i]; 
            in = i; 
        } 
    } 
    cout<<(char)in<<" "<<min; 
} 
 
