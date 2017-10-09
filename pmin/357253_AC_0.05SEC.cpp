#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int arr[101]; 
    int min=2147483647; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
        if(arr[i]<min) min = arr[i]; 
    } 
      
    for(int i=0;i<n;i++) { 
        if(arr[i] == min) { 
            cout<<i+1<<" "; 
        } 
    } 
    return 0; 
} 
 
