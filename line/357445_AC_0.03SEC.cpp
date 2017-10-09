#include <iostream> 
using namespace std; 
int main () { 
    int n; 
    int arr[101]; 
    int arr2[101]; 
    cin>>n; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
    } 
      
    int max=1; 
    arr2[0]=1; 
    for(int i=1;i<n;i++) { 
        for(int j=max+1;j>=max-arr[i]+1;j--) { 
                arr2[j] = arr2[j-1]; 
                arr2[j-1]=0; 
        } 
              
        arr2[max-arr[i]] = i+1; 
          
        max++; 
    } 
      
    for(int i=0;i<n;i++) cout<<arr2[i]<<" "; 
} 
 
