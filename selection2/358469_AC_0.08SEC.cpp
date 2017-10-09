#include <iostream> 
using namespace std; 
int main() { 
    int n,a; 
    int arr[1100]; 
    cin>>n>>a; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
  
    for(int i=0;i<a;i++) { 
              
        for(int j=i+1;j<n;j++) { 
            if(arr[i] > arr[j]) { 
                int temp=arr[i]; 
                arr[i]=arr[j]; 
                arr[j]=temp; 
            } 
        } 
          
    } 
      
    for(int i=0;i<n;i++) cout<<arr[i]<<" "; 
} 
 
