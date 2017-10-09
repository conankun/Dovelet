#include <iostream> 
using namespace std; 
int main() { 
    int arr[10]; 
    int max=0; 
    int min=2147483647; 
    int sum=0; 
    for(int i=0;i<10;i++) { 
        cin>>arr[i]; 
        if(arr[i] > max) max = arr[i]; 
        if(arr[i] < min) min = arr[i]; 
        sum+=arr[i];     
    } 
    cout<<sum<<" "<<max<<" "<<min; 
    return 0; 
} 
 
