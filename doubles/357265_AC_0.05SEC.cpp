#include <iostream> 
using namespace std; 
int main() { 
    int arr[100]; 
    int i; 
    for(i=0;;i++) { 
        cin>>arr[i]; 
        if(arr[i] == 0) break; 
    } 
      
  
    int c=0; 
    for(int a=0;a<=i-1;a++) { 
    for(int j=0;j<=i;j++) { 
        if(arr[a] * 2 == arr[j]) { 
            c++; 
        } 
    } 
    } 
      
      
    cout<<c; 
      
    return 0; 
} 
 
