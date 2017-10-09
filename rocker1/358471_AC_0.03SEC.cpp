#include <iostream> 
#include <algorithm> 
using namespace std; 
int main() { 
    int n,t; 
    int arr[201]; 
    cin>>n>>t; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
  
  
    sort(arr,arr+n); 
  
    int count=0; 
    int sum=0; 
    for(int i=0;i<n;i++) { 
        sum+=arr[i]; 
        if(sum > t) break; 
        else { 
            count++; 
        } 
    } 
  
    cout<<count; 
  
} 
 
