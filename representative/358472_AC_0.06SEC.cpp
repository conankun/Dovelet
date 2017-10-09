#include <iostream> 
using namespace std; 
int main() { 
    int arr[5]; 
    int argv=0; 
    int i,j; 
    for(i=0;i<5;i++) { 
        cin>>arr[i]; 
        argv+=arr[i]; 
    } 
    argv/=5; 
  
    cout<<argv<<endl; 
  
    for(i=0;i<5;i++) { 
        for(j=0;j<4;j++) { 
            if(arr[j] > arr[j+1]) { 
                int temp=arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1]=temp; 
            } 
        } 
    } 
  
  
    cout<<arr[2]; 
  
    return 0; 
} 
 
