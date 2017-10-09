#include<iostream> 
using namespace std; 
int map[1001][1001]={0}; 
int vis[1001]={0}; 
int sum[1001]={0}; 
int main() { 
    int n,m; 
    cin>>n>>m; 
    for(int i=0;i<m;i++) { 
        int p; 
        cin>>p; 
        int r; 
        int a; 
        cin>>r; 
        for(int j=0;j<p-1;j++) { 
            cin>>a; 
            map[a][r] = 1; 
            r = a; 
            sum[a]++; 
        } 
    } 
    int count=n; 
    int arr[1000]={0}; 
    int in=0; 
    while(count--) { 
        int s=-1; 
        for(int i=1;i<=n;i++) { 
            if(sum[i] == 0 && vis[i] == 0) { 
                s = i; 
                break; 
            } 
        } 
  
        if(s == -1) { 
            cout<<0; 
            return 0; 
        } 
  
        for(int j=1;j<=n;j++) { 
            if(map[j][s] == 1) { 
                sum[j]-=1; 
            } 
        } 
        vis[s]=1; 
        arr[in++]=s; 
    } 
    for(int i=0;i<in;i++) cout<<arr[i]<<endl; 
} 
 
