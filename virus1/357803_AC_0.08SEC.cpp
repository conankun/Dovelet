#include<iostream> 
using namespace std; 
  
int n,r; 
int arr[101][101]; 
int arr2[101]={0,}; 
  
void graph(int i) { 
    for(int j=1;j<=n;j++) { 
        if(arr[i][j] == 1 && i!=j && arr2[j] != 1) { 
            arr2[j]=1; 
            graph(j); 
        } 
    } 
} 
  
int main() { 
    cin>>n>>r; 
    for(int i=0;i<r;i++) { 
        int a,b; 
        cin>>a>>b; 
        arr[a][b]=1; 
        arr[b][a]=1; 
    } 
    graph(1); 
    int cnt=0; 
    for(int i=2;i<=n;i++) cnt+=arr2[i]; 
    cout<<cnt; 
} 
 
