#include<iostream> 
using namespace std; 
int n; 
int graph[101][101]={0}; 
int sum[101]={0}; 
int main() { 
    cin>>n; 
    int a,b; 
    while(cin>>a>>b) { 
        graph[a][b]=1; 
    } 
    //sum구함 
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=n;j++) { 
            sum[i]+=graph[j][i]; 
        } 
    } 
    int r=n; 
    int arr[101]={0}; 
    int in=0; 
    while(r--) { 
        int s; 
        bool t=false; 
        for(int i=1;i<=n;i++) { 
            if(sum[i] == 0) { 
                t=true; 
                s = i; 
                break; 
            } 
        } 
        if(!t) { 
            cout<<"impossible"; 
            return 0; 
        } 
        arr[in++]=s; 
        for(int i=1;i<=n;i++) { 
            if(graph[s][i] == 1) { 
                sum[i]--; 
            } 
        } 
        sum[s]=-1; 
    } 
    for(int i=0;i<in;i++) { 
        cout<<arr[i]<<" "; 
    } 
} 
 
