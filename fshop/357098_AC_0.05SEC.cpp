#include<iostream> 
using namespace std; 
int f,v; 
int arr[101][101]={0}; 
int dp[101][101]={0}; 
int main() { 
    cin>>f>>v; 
    for(int i=1;i<=f;i++) { 
        for(int j=1;j<=v;j++) { 
            cin>>arr[i][j]; 
        } 
    } 
  
    for(int i=1;i<=v;i++) { 
        dp[1][i] = arr[1][i]; 
    } 
  
    for(int i=2;i<=f;i++) { 
        for(int j=i;j<=v;j++) { 
            int max=-1001; 
            for(int k=j-1;k>=i-1;k--) { 
                if(arr[i][j]+dp[i-1][k] > max) { 
                    max = arr[i][j]+dp[i-1][k]; 
                } 
            } 
            dp[i][j]=max; 
        } 
    } 
    int max=-1001; 
    for(int i=f;i<=v;i++) { 
        if(dp[f][i] > max) max = dp[f][i]; 
    } 
    cout<<max; 
} 
 
