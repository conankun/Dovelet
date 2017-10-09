#include <iostream>   
using namespace std; 
int main () { 
    int arr[4]; 
    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]; 
    if(arr[1]-arr[0] == arr[2]-arr[1]) { 
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[3]+arr[1]-arr[0]; 
    } else if(arr[0]/arr[1] == arr[1]/arr[2]) { 
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[3]*((float)arr[1]/arr[0]); 
    } 
    return 0; 
} 
 
