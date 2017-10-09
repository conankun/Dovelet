#include<iostream> 
#include<algorithm> 
using namespace std; 
int dp[51][201]={0}; 
int arr[201]={0}; 
int main() { 
    int m,s,c; 
    cin>>m>>s>>c; 
    for(int i=1;i<=c;i++) cin>>arr[i]; 
    sort(arr+1,arr+c+1); 
    for(int i=1;i<=c;i++) { 
        dp[1][i] = arr[i]-arr[1]+1; 
    } 
    for(int i=2;i<=m;i++) { 
        for(int j=i;j<=c;j++) { 
            dp[i][j] = dp[i-1][j-1]+1; 
            for(int k=j-1;k>=i;k--) { //얘가 i번째 판자의 시작점일때 
                dp[i][j] = min(dp[i-1][k-1]+arr[j]-arr[k]+1,dp[i][j]); 
            } 
        } 
    } 
    int m_n=99999999; 
    for(int i=1;i<=m;i++) { 
        if(dp[i][c] != 0 && dp[i][c] < m_n) m_n = dp[i][c]; 
    } 
    cout<<m_n; 
}