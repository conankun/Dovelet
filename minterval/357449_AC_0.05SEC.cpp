#include <iostream> 
using namespace std; 
int main() { 
    int i; 
    int arr[2001]; 
    int arr2[2001]={0,}; 
    for(i=0;;i++) { 
        cin>>arr[i]; 
        if(arr[i] == 0) break; 
    } 
    i--; 
  
    arr2[0]=arr[0]; 
    for(int x=1;x<=i;x++) { 
        arr2[x] = arr2[x-1]+arr[x] > arr[x] ? arr2[x-1]+arr[x] : arr[x]; 
    } 
  
    int max=arr2[0]; 
    for(int x=2;x<=i;x++) { 
        if(arr2[x] > max) max = arr2[x]; 
    } 
    cout<<max; 
} 
 
