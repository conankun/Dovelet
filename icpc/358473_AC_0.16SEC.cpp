#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    int arr[101]; 
    int max=0; 
    int min=2147483647; 
    int sum=0; 
    cin>>n; 
  
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
        if(arr[i] > max) max=arr[i]; 
        if(arr[i] < min) min = arr[i]; 
        sum+=arr[i]; 
    } 
  
    sum-=max; 
    sum-=min; 
  
    sum/=(n-2); 
  
    cout<<sum; 
  
  
      
} 
 
