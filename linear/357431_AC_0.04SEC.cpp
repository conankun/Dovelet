#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    int arr[1000]; 
    cin>>n; 
      
    for(int i=0;i<n;i++) cin>>arr[i]; 
      
    int c=0; 
    for(int i=0;i<n;i++) { 
        for(int j=i+1;j<n;j++) { 
            for(int z=j+1;z<n;z++) { 
            if(arr[j]-arr[i] == arr[z]-arr[j]) { 
            c++; 
            } 
            } 
        } 
    } 
      
    cout<<c; 
} 
 
