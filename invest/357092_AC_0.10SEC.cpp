#include <iostream> 
using namespace std; 
struct ab{ 
    int a,b; 
}; 
int m,n; 
int data[21][301]={0}; 
int dp[21][301]={0}; 
ab gold[21][301]={0,0}; 
void tu(int i,int j) { 
    if(i == 2) { 
        cout<<gold[i][j].a<<" "; 
        cout<<gold[i][j].b<<" "; 
        return; 
    } 
    tu(i-1,gold[i][j].a); 
    cout<<gold[i][j].b<<" "; 
    return; 
} 
int main() { 
    cin>>m>>n; 
    for(int i=1;i<=m;i++) { 
       for(int j=1;j<=n;j++) { 
        cin>>data[j][i]; 
      } 
    } 
    for(int i=1;i<=m;i++) { 
        dp[1][i]=data[1][i]; 
        gold[1][i].a = 0; 
    } 
    for(int i=2;i<=n;i++) { 
        for(int j=0;j<=m;j++) { 
            int l; 
            dp[i][j]=data[i][j]; 
            for(int k=j;k>=0;k--) { 
                l=j-k; 
                if(dp[i-1][l]+ data[i][k] >= dp[i][j]) { 
                dp[i][j]=max(dp[i-1][l]+ data[i][k],dp[i][j]); 
                    gold[i][j].a = l; 
                    gold[i][j].b = k; 
                } 
            } 
        } 
    } 
    cout<<dp[n][m]<<endl; 
    tu(n,m); 
} 
 
