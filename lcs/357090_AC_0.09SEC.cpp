#include<iostream> 
using namespace std; 
int arr1[1001]={0}; 
int arr2[1001]={0}; 
int dp[1001][1001]={0}; 
int bt[1001][1001]={0}; 
int btl[1000]={0}; 
int main() { 
    int x,y; 
    cin>>x>>y; 
    for(int i=1;i<=x;i++) cin>>arr1[i]; 
    for(int i=1;i<=y;i++) cin>>arr2[i]; 
    int mx=0; 
    for(int i=1;i<=x;i++) { 
        for(int j=1;j<=y;j++) { 
            if(arr1[i] == arr2[j]) { 
                dp[i][j]=dp[i-1][j-1]+1; 
                bt[i][j]=1; 
            } else if(dp[i-1][j] > dp[i][j-1]) { 
                dp[i][j]=dp[i-1][j]; 
                bt[i][j]=2; 
            } else { 
                dp[i][j]=dp[i][j-1]; 
                bt[i][j]=3; 
            } 
            if(dp[i][j] > mx) mx = dp[i][j]; 
        } 
    } 
      
    cout<<mx<<endl; 
    int cc=0; 
    int index=0; 
    int x1=x,y1=y; 
    while(cc<mx) { 
        if(bt[x1][y1] == 1) { 
            btl[index]=arr1[x1]; 
            index++; 
            x1-=1; 
            y1-=1; 
            cc++; 
        } else if(bt[x1][y1] == 2) { 
            x1-=1; 
        } else { 
            y1-=1; 
        } 
    } 
    for(int i=index-1;i>=0;i--) cout<<btl[i]<<" "; 
} 
 
