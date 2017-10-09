#include <iostream> 
using namespace std; 
int main() { 
    int arr[31]; 
    int i; 
    int max=0; 
    for(i=0;;i++) { 
        cin>>arr[i]; 
        if(arr[i]==0) { 
            i--; 
            break; 
        } 
        if(arr[i] > max) max = arr[i]; 
    } 
  
    for(int j=max;j>=1;j--) { 
        for(int z=0;z<=i;z++) { 
            cout<<" "; 
            if(arr[z] >= j) cout<<"*"; 
            else cout<<" "; 
        } 
        cout<<endl; 
    } 
  
    for(int j=0;j<=i;j++) cout<<" "<<arr[j]; 
  
} 
 
