#include<iostream>  
using namespace std;  
char dp[255][255]={0}; 
void pp(int i,int j,int z) { 
    for(int k=0;k<255;k++) { 
        char a=dp[i][k]+dp[j][k]; 
        dp[z][k]+=a; 
        while(dp[z][k] >= 10) { 
            dp[z][k]-=10; 
            dp[z][k+1]++; 
        } 
          
    } 
} 
int main() {  
    int n;  
    scanf("%d",&n);  
    dp[0][0]=1;  
    dp[1][0]=1;  
    for(int i=2;i<=n;i++) {  
       // dp[i]=dp[i-1]+2*(dp[i-2]);  
        pp(i,i-1,i); 
        pp(i-2,i-2,i); 
    } 
    bool a=false; 
    for(int i=n-1;i>=0;i--) { 
        if(dp[n][i] != 0) a = true; 
        if(a) cout<<(char)(dp[n][i]+48); 
    } 
} 
 
