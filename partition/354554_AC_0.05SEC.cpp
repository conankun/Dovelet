 #include<iostream> 
using namespace std; 
int main() { 
    int n; 
    int dp[51]={0,}; 
    cin>>n; 
    dp[0]=1; 
    dp[1]=1; 
    dp[2]=2; 
    dp[3]=3; 
    dp[4]=5; 
    dp[5]=7; 
    for(int i=6;i<=n;i++) { 
        int cnt=1; 
        for(int j=i-1;;) { 
            if(j<0)break; 
            if(cnt %2==1) 
            dp[i]+=dp[j]; 
            else
            dp[i]-=dp[j]; 
  
            j-=cnt; 
            if(j < 0) break; 
            if(cnt %2==1) 
            dp[i]+=dp[j]; 
            else
            dp[i]-=dp[j]; 
            j-=(cnt*2+1); 
            cnt++; 
        } 
    } 
    cout<<dp[n]; 
} 
 
