#include<iostream> 
using namespace std; 
  
int gcd(int a,int b) { 
    int c; 
    do { 
        c = a%b; 
        a = b; 
        b = c; 
    }while(c!=0); 
    return a; 
} 
  
int main() { 
    int n; 
    int arr[101]; 
    int dp[101]; 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
    dp[0]=arr[0]; 
    for(int i=1;i<n;i++) { 
        dp[i]=gcd(dp[i-1],arr[i]); 
    } 
    cout<<dp[n-1]; 
} 
 
