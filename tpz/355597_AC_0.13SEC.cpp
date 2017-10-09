#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int arr[3]; 
    int min=2147483647; 
    for(int i=0;i<3;i++) { 
        cin>>arr[i]; 
        if(arr[i] < min) min = arr[i]; 
    } 
  
    int a= arr[0]+arr[1] - n; 
    if(a < 0) a = 0; 
    int b = a+arr[2] - n; 
    if(b < 0) b = 0; 
    cout<<min<<" "<<b; 
} 
 
