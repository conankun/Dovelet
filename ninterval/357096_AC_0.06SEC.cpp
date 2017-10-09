#include<iostream> 
using namespace std; 
int dp[101][101]={0}; 
int arr[101]={0}; 
int minindex=99999999; 
int maxmin(int s,int k) { 
    int max=0,mn=99999999; 
    for(int i=s;i<=k;i++) { 
        if(arr[i] > max) { 
            max = arr[i]; 
            minindex=min(minindex,i); 
        } 
        if(arr[i] < mn) {  
            mn =arr[i]; 
            minindex=min(minindex,i); 
        } 
    } 
    return max-mn; 
} 
int main() { 
    int n,m; 
    cin>>n>>m; 
    for(int i=1;i<=n;i++) cin>>arr[i]; 
      
    for(int i=1;i<=m;i++) { 
        for(int j=2*i;j<=n;j++) { 
            for(int k=2*i-1;k<=j-1;k++) { 
                minindex=99999999; 
                dp[i][j]=max(dp[i][j],maxmin(k,j)+dp[i-1][minindex-1]); 
            } 
        } 
    } 
    int a=0; 
    for(int i=1;i<=n;i++) { 
        if(dp[m][i] > a) a = dp[m][i]; 
    } 
    cout<<a; 
} 
 
