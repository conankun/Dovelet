#include<iostream> 
using namespace std; 
int n; 
int dp[10001][7]={0}; //밑면이 j일때 최대값이 저장된다. 
int side[7]={0,6,4,5,2,3,1}; 
int data[10001][7]={0}; 
int main() { 
    cin>>n; 
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=6;j++) { 
            cin>>data[i][j]; 
        } 
    } 
  
    //초기값 셋팅. 
    for(int i=1;i<=6;i++) { 
        for(int j=1;j<=6;j++) { 
            if(j != i && j != side[i]) { 
                if(dp[1][data[1][i]] < data[1][j]) { 
                    dp[1][data[1][i]] = data[1][j]; 
                } 
            } 
        } 
    } 
    //시작 
    for(int i=2;i<=n;i++) { //n개만큼 돌려서 
        for(int j=1;j<=6;j++) { //i번째 주사위의 윗변이 j 
            int mx=0; 
            for(int k=1;k<=6;k++) { 
                if(k != j && k != side[j] && data[i][k] > mx) { 
                    mx = data[i][k]; 
                } 
            } 
              
            dp[i][data[i][j]] = dp[i-1][data[i][side[j]]]+mx; 
        } 
    } 
    int mx=0; 
    for(int i=1;i<=6;i++) if(dp[n][i] > mx) mx = dp[n][i]; 
    cout<<mx; 
} 
 
