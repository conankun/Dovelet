#include <iostream> 
  
using namespace std; 
  
int main() { 
    int n; 
    int arr[52]; 
    cin>>n; 
    int argv=0; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
        argv+=arr[i]; 
    } 
    argv/=n; 
      
    int sum=0; 
    for(int j=0;j<n;j++) { 
        if(arr[j] > argv) sum+=(arr[j]-argv); 
    } 
      
    cout<<"The minimum number of moves is "<<sum<<"."; 
} 
 
