#include <iostream> 
using namespace std; 
  
int main() { 
    int n; 
    int count=0; 
    int arr[1001]; 
    cin>>n; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
        int yn=0; 
        if(i >= 1) { 
        for(int j=0;j<i;j++) { 
            if(arr[j] == arr[i]) yn=1; 
            } 
        } 
          
        if(yn == 0) count++; 
    } 
      
    cout<<count; 
    return 0; 
} 
 
