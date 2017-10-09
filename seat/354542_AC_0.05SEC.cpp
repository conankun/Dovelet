 #include<iostream> 
using namespace std; 
int main() { 
    int n,m; 
    int a[41]={0}; 
    int dp[41]={1,1}; 
    int g; 
    int s=1; 
    cin>>n>>m; 
    for(int i=0;i<m;i++) { 
        cin>>g; 
        a[g]=1;//고정석 
    } 
  
    for(int i=2;i<=40;i++) { 
        dp[i]=dp[i-1]+dp[i-2]; 
    } 
  
    int in=0; 
    for(int i=1;i<=n+1;i++) { 
        if(a[i] == 1 || i ==n+1) { 
            s*=dp[in]; 
            in=0; 
            continue; 
        } else { 
            ++in; 
        } 
  
    } 
    cout<<s; 
} 