#include<iostream> 
#include<algorithm> 
using namespace std; 
int arr[100]; 
int dp[20001][101]={0}; 
int main() { 
    int n; 
    int sum=0; 
    cin>>n; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
        sum+=arr[i]; 
    } 
    sort(arr,arr+n); 
    int mx=0; 
    int min=999999; 
    int a,b; 
    dp[0][0]=1; 
    for(int i=0;i<n;i++) { 
        int mx2=0; 
        for(int j=mx;j>=0;j--) { 
            for(int k=0;k<=100;k++) { 
                if(dp[j][k] == 1 && j+arr[i] <= sum) { 
                    dp[j+arr[i]][k+1]=1; 
                    if(abs((j+arr[i])-(sum-(j+arr[i]))) < min && abs((k+1)-(n-(k+1))) == (n % 2 == 0 ? 0 : 1)) { 
                        a = j+arr[i]; 
                        b = sum-a; 
                        min = abs(a-b); 
                    } 
                    if(mx2 < j+arr[i]) mx2 = j+arr[i]; 
                } 
            } 
        } 
        if(mx2 > mx) mx = mx2; 
    } 
    if(a > b)  
    { 
        int temp=a; 
        a = b; 
        b = temp; 
    } 
    cout<<a<<" "<<b; 
} 