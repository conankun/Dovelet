#include <iostream> 
using namespace std; 
int main () { 
    int n; 
    int arr[1001]; 
    cin>>n; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
    } 
      
    int rank; 
    for(int i=0;i<n;i++) { 
        rank=1; 
        for(int j=0;j<n;j++) { 
            if(j != i) 
            if(arr[j] > arr[i]) rank++; 
        } 
          
        cout<<rank<<endl; 
    } 
      
      
    return 0; 
} 
 
