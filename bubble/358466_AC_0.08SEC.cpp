#include <iostream> 
  
using namespace std; 
  
int main() { 
    int n,m; 
    int arr[1001]; 
    cin>>n>>m; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
    } 
      
    for(int i=0;i<m;i++) { 
      
      
        for(int j=0;j<n-1;j++) { 
            if(arr[j] > arr[j+1]) { 
                int temp=arr[j]; 
                arr[j]=arr[j+1]; 
                arr[j+1]=temp; 
            } 
        } 
          
    } 
      
    for(int i=0;i<n;i++) { 
        cout<<arr[i]<<" "; 
    } 
    return 0; 
} 
 
