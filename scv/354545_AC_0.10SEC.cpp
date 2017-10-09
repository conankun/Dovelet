#include<iostream> 
using namespace std; 
int main() { 
    int n; 
    int arr[101][101]; 
    int arr2[101][101]={0,}; 
    cin>>n; 
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>arr[i][j]; 
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=n;j++) { 
            arr2[i][j]=max(arr2[i-1][j]+arr[i][j],arr2[i][j-1]+arr[i][j]); 
        } 
    } 
    cout<<arr2[n][n]; 
} 
 
